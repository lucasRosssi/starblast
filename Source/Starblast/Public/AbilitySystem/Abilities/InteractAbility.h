// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/BaseAbility.h"
#include "InteractAbility.generated.h"

class AStarCharacter;

USTRUCT(BlueprintType)
struct FInteractionData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	const AActor* Target = nullptr;
  
	UPROPERTY(BlueprintReadOnly)
	const AStarCharacter* InstigatorCharacter = nullptr;
};

/**
 * 
 */
UCLASS()
class STARBLAST_API UInteractAbility : public UBaseAbility
{
	GENERATED_BODY()

public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ActivateInteraction(const FInteractionData& InteractionData);

private:
	
};
