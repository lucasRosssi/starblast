// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/StarAnimInstance.h"

#include "StarTags.h"
#include "AbilitySystem/StarAbilitySystemComponent.h"
#include "Characters/StarCharacter.h"

void UStarAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	StarCharacter = Cast<AStarCharacter>(TryGetPawnOwner());

	if (StarCharacter)
	{
		ListenForCombatStateChange();
	}
}

void UStarAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (StarCharacter == nullptr)
	{
		StarCharacter = Cast<AStarCharacter>(TryGetPawnOwner());
		
		if (StarCharacter)
		{
			ListenForCombatStateChange();
		}
	}

	if (StarCharacter == nullptr) return;

	bWeaponEquipped = StarCharacter->IsWeaponEquipped();
}

void UStarAnimInstance::ListenForCombatStateChange()
{
	AbilitySystemComponent = StarCharacter->GetStarASC();

	if (AbilitySystemComponent)
	{
		RegisterCombatStateTagEvents();
	}
	else
	{
		StarCharacter->ASCRegisteredDelegate.AddUObject(this, &UStarAnimInstance::OnASCRegistered);
	}
}

void UStarAnimInstance::RegisterCombatStateTagEvents()
{
	const FStarTags& StarTags = FStarTags::Get();
	for (const FGameplayTag& CombatStateTag : StarTags.ParentsToChildren[StarTags.Combat_State])
	{
		AbilitySystemComponent->RegisterGameplayTagEvent(CombatStateTag)
			.AddUObject(this, &UStarAnimInstance::OnCombatStateChanged);
	}
}

void UStarAnimInstance::OnCombatStateChanged(const FGameplayTag CallbackTag, int32 NewCount)
{
	if (NewCount > 0)
	{
		CombatStateContainer.AddTag(CallbackTag);
	}
	else
	{
		CombatStateContainer.RemoveTag(CallbackTag);
	}
}

void UStarAnimInstance::OnASCRegistered(UStarAbilitySystemComponent* InAbilitySystemComponent)
{
	AbilitySystemComponent = InAbilitySystemComponent;
	RegisterCombatStateTagEvents();
}
