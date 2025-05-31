// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/StarAbilitySystemComponent.h"

#include "AbilitySystem/Abilities/BaseAbility.h"

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
		else if (const UBaseAbility* ActiveAbility = Cast<UBaseAbility>(AbilitySpec.Ability))
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
		if (const UBaseAbility* ActiveAbility = Cast<UBaseAbility>(AbilitySpec.Ability))
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
		if (!Cast<UBaseAbility>(AbilitySpec.Ability)) continue;

		InputConfirm();
		break;
	}
}

void UStarAbilitySystemComponent::CancelPressed()
{
	for (auto& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.IsActive()) continue;
		if (!Cast<UBaseAbility>(AbilitySpec.Ability)) continue;

		InputCancel();
		break;
	}
}
