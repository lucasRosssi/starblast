// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemy.h"

#include "AbilitySystem/StarAbilitySystemComponent.h"
#include "AbilitySystem/StarAttributeSet.h"
#include "Components/LoadoutComponent.h"

AEnemy::AEnemy()
{
	AbilitySystemComponent = CreateDefaultSubobject<UStarAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UStarAttributeSet>("AttributeSet");
	Loadout = CreateDefaultSubobject<ULoadoutComponent>("Loadout");
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AEnemy::InitAbilityActorInfo()
{
	
}
