// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/StarPlayerState.h"

#include "AbilitySystem/StarAbilitySystemComponent.h"
#include "AbilitySystem/StarAttributeSet.h"
#include "Components/LoadoutComponent.h"

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
