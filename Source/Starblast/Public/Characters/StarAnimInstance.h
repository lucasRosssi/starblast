// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimInstance.h"
#include "StarAnimInstance.generated.h"

class UStarAbilitySystemComponent;
class AStarCharacter;
/**
 * 
 */
UCLASS()
class STARBLAST_API UStarAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AStarCharacter> StarCharacter = nullptr;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UStarAbilitySystemComponent> AbilitySystemComponent = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	bool bWeaponEquipped = false;

	UPROPERTY(BlueprintReadOnly)
	FGameplayTagContainer CombatStateContainer = FGameplayTagContainer();
	
private:
	void ListenForCombatStateChange();
	void RegisterCombatStateTagEvents();
	
	void OnCombatStateChanged(const FGameplayTag CallbackTag, int32 NewCount);
	void OnASCRegistered(UStarAbilitySystemComponent* InAbilitySystemComponent);
};
