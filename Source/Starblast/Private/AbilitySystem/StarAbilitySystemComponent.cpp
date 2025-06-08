// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/StarAbilitySystemComponent.h"

#include "AbilitySystem/Abilities/ActiveAbility.h"

void UStarAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(
		this,
		&UStarAbilitySystemComponent::EffectApplied
	);
	
}

void UStarAbilitySystemComponent::AddStartupAbilities(const TArray<TSubclassOf<UGameplayAbility>>& InAbilities)
{
	for (const auto AbilityClass : InAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		if (const auto* ActiveAbility = Cast<UActiveAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.GetDynamicSpecSourceTags().AddTag(ActiveAbility->StartupInputTag);
		}
		GiveAbility(AbilitySpec);
	}

	bStartupAbilitiesGiven = true;
	AbilitiesGivenDelegate.Broadcast();
}

void UStarAbilitySystemComponent::AbilityInputTagPressed(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (auto& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag)) continue;

		AbilitySpecInputPressed(AbilitySpec);

		if (AbilitySpec.IsActive() && AbilitySpec.GetPrimaryInstance())
		{
			InvokeReplicatedEvent(
				EAbilityGenericReplicatedEvent::InputPressed,
				AbilitySpec.Handle,
				AbilitySpec.GetPrimaryInstance()->GetCurrentActivationInfo().GetActivationPredictionKey()
			);
		}
		else if (const UActiveAbility* ActiveAbility = Cast<UActiveAbility>(AbilitySpec.Ability))
		{
			if (!ActiveAbility->bCanHoldInput) TryActivateAbility(AbilitySpec.Handle);
		}

		break;
	}
}

void UStarAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (auto& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag)) continue;
		if (const UActiveAbility* ActiveAbility = Cast<UActiveAbility>(AbilitySpec.Ability))
		{
			if (!ActiveAbility->bCanHoldInput) break;
		}

		AbilitySpecInputPressed(AbilitySpec);

		if (AbilitySpec.IsActive()) break;

		TryActivateAbility(AbilitySpec.Handle);
		break;
	}
}

void UStarAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (auto& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag)) continue;
		if (!AbilitySpec.IsActive() || !AbilitySpec.GetPrimaryInstance()) break;

		AbilitySpecInputReleased(AbilitySpec);
		InvokeReplicatedEvent(
			EAbilityGenericReplicatedEvent::InputReleased,
			AbilitySpec.Handle,
			AbilitySpec.GetPrimaryInstance()->GetCurrentActivationInfo().GetActivationPredictionKey()
		);
		break;
	}
}

void UStarAbilitySystemComponent::ConfirmPressed()
{
	for (auto& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.IsActive()) continue;
		if (!Cast<UActiveAbility>(AbilitySpec.Ability)) continue;

		InputConfirm();
		break;
	}
}

void UStarAbilitySystemComponent::CancelPressed()
{
	for (auto& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.IsActive()) continue;
		if (!Cast<UActiveAbility>(AbilitySpec.Ability)) continue;

		InputCancel();
		break;
	}
}

void UStarAbilitySystemComponent::EffectApplied(
	UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec,
	FActiveGameplayEffectHandle ActiveEffectHandle
)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
}
