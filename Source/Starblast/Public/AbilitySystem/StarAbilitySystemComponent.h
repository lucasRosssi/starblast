// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "StarAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer& /* AssetTags */)
DECLARE_MULTICAST_DELEGATE(FAbilitiesGiven);
DECLARE_DELEGATE_OneParam(FCombatStateChanged, const FGameplayTag&);

/**
 * 
 */
UCLASS()
class STARBLAST_API UStarAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet();
	void AddStartupAbilities(const TArray<TSubclassOf<UGameplayAbility>>& InAbilities);
	
	void AbilityInputTagPressed(const FGameplayTag& InputTag);
	void AbilityInputTagHeld(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);

	void ConfirmPressed();
	void CancelPressed();

	FAbilitiesGiven AbilitiesGivenDelegate;
	FEffectAssetTags EffectAssetTags;
	FCombatStateChanged CombatStateChangedDelegate;

	bool bStartupAbilitiesGiven = false;

protected:
	void EffectApplied(
		UAbilitySystemComponent* AbilitySystemComponent,
		const FGameplayEffectSpec& EffectSpec,
		FActiveGameplayEffectHandle ActiveEffectHandle
	);
	
private:
	
};
