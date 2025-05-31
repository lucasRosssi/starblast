// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/StarPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/StarAbilitySystemComponent.h"
#include "Inputs/StarInputComponent.h"

void AStarPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UStarInputComponent* StarInputComponent = CastChecked<UStarInputComponent>
	(InputComponent);
	
	StarInputComponent->BindAction(
		ConfirmAction,
		ETriggerEvent::Started,
		this,
		&AStarPlayerController::ConfirmPressed
	);
	StarInputComponent->BindAction(
		CancelAction,
		ETriggerEvent::Started,
		this,
		&AStarPlayerController::CancelPressed
	);
	StarInputComponent->BindAction(
		InteractAction,
		ETriggerEvent::Started,
		this,
		&AStarPlayerController::InteractPressed
	);

	StarInputComponent->BindAbilityActions(
		InputConfig,
		this,
		&ThisClass::AbilityInputTagPressed,
		&ThisClass::AbilityInputTagReleased,
		&ThisClass::AbilityInputTagHeld
	);
}

void AStarPlayerController::AbilityInputTagPressed(const FGameplayTag& InputTag)
{
	GetASC()->AbilityInputTagPressed(InputTag);
}

void AStarPlayerController::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	GetASC()->AbilityInputTagReleased(InputTag);
}

void AStarPlayerController::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	GetASC()->AbilityInputTagHeld(InputTag);
}

void AStarPlayerController::ConfirmPressed()
{
	GetASC()->ConfirmPressed();
}

void AStarPlayerController::CancelPressed()
{
	GetASC()->CancelPressed();
}

void AStarPlayerController::InteractPressed()
{
	// if (InteractablesInRange.IsEmpty()) return;
 //  
	// const UInteractComponent* Interactable = InteractablesInRange[InteractablesInRange.Num() - 1];
	// if (!IsValid(Interactable))
	// {
	// 	RemoveInteractableInRange(Interactable);
	// 	return;
	// }
	//
	// if (!Interactable->IsEnabled()) return;
	//
	// Interactable->BeginInteract(this);
}

UStarAbilitySystemComponent* AStarPlayerController::GetASC()
{
	if (StarASC == nullptr)
	{
		auto ASC = UAbilitySystemBlueprintLibrary::
			GetAbilitySystemComponent(GetPawn<APawn>());
		StarASC = Cast<UStarAbilitySystemComponent>(ASC);

	}
	
	return StarASC;
}
