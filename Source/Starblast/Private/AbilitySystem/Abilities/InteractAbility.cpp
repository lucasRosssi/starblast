// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/InteractAbility.h"

#include "Characters/StarCharacter.h"

void UInteractAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData
)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!TriggerEventData)
	{
		UE_LOG(LogTemp, Error, TEXT("InteractAbility activation failed! No Event Data provided!"));
		return;
	}

	FInteractionData InteractionData;
	InteractionData.Target = TriggerEventData->Target;
	InteractionData.InstigatorCharacter = Cast<AStarCharacter>(TriggerEventData->Instigator);
	ActivateInteraction(InteractionData);
}
