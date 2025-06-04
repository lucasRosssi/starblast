// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/BaseAbility.h"
#include "ActiveAbility.generated.h"

/**
 * 
 */
UCLASS()
class STARBLAST_API UActiveAbility : public UBaseAbility
{
	GENERATED_BODY()

public:
	// Starting input for the player, when the ability is granted
	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(DisplayPriority=1))
	FGameplayTag StartupInputTag;
	// True if the ability should target accordingly to the player movement input direction 
	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(DisplayPriority=2))
	bool bCanHoldInput = false;
	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(DisplayPriority=3))
	bool bUsesMovementInputDirection = false;
protected:
	
private:
	
};
