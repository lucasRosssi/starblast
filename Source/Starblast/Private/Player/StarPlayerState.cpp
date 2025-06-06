// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/StarPlayerState.h"

#include "AbilitySystem/StarAbilitySystemComponent.h"
#include "AbilitySystem/StarAttributeSet.h"
#include "Characters/StarCharacter.h"
#include "Components/LoadoutComponent.h"
#include "Starblast/StarblastMacros.h"

AStarPlayerState::AStarPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UStarAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UStarAttributeSet>("AttributeSet");
	Loadout = CreateDefaultSubobject<ULoadoutComponent>("Loadout");

	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* AStarPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AStarPlayerState::BeginPlay()
{
	Super::BeginPlay();

	OnPawnSet.AddDynamic(this, &AStarPlayerState::OnPawnChanged);
}

void AStarPlayerState::OnPawnChanged(APlayerState* Player, APawn* NewPawn, APawn* OldPawn)
{
	AStarCharacter* StarCharacter = Cast<AStarCharacter>(NewPawn);
	GUARD(StarCharacter,, TEXT("Player pawn changed to a non Star Character: %s!"), *NewPawn->GetName())
	Loadout->Character = StarCharacter;
}
