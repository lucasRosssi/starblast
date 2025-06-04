// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/StarPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/StarAbilitySystemComponent.h"
#include "Characters/Hero.h"
#include "Components/InteractComponent.h"
#include "Inputs/StarInputComponent.h"
#include "Starblast/StarblastMacros.h"

void AStarPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UStarInputComponent* StarInputComponent = Cast<UStarInputComponent>
	(InputComponent);

	GUARD(StarInputComponent,, TEXT("Star Input Component was not set!"));
	
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

void AStarPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	GetASC()->AbilityInputTagPressed(InputTag);
}

void AStarPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	GetASC()->AbilityInputTagReleased(InputTag);
}

void AStarPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
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
	GUARD(GetHeroPawn(),, TEXT("Pawn is not of Hero class!"));

	UInteractComponent* InteractComponentInRange = HeroPawn->GetInteractComponentInRange();

	if (!InteractComponentInRange) return;

	InteractComponentInRange->OnInteracted(HeroPawn);
}

UStarAbilitySystemComponent* AStarPlayerController::GetASC()
{
	if (StarASC == nullptr)
	{
		auto ASC = UAbilitySystemBlueprintLibrary::
			GetAbilitySystemComponent(GetPawn());
		StarASC = Cast<UStarAbilitySystemComponent>(ASC);

	}
	
	return StarASC;
}

AHero* AStarPlayerController::GetHeroPawn()
{
	if (HeroPawn == nullptr)
	{
		HeroPawn = GetPawn<AHero>();
	}

	return HeroPawn;
}
