// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Hero.h"

#include "AbilitySystem/StarAbilitySystemComponent.h"
#include "Components/LoadoutComponent.h"
#include "Player/StarPlayerState.h"
#include "Starblast/StarblastMacros.h"

AHero::AHero()
{
	
}

void AHero::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the server
	InitAbilityActorInfo();
}

void AHero::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the client
	InitAbilityActorInfo();
}

ULoadoutComponent* AHero::GetLoadout()
{
	if (Loadout == nullptr)
	{
		if (const AStarPlayerState* PS = GetPlayerState<AStarPlayerState>())
		{
			Loadout = PS->GetLoadout();
		}
	}

	return Loadout;
}

void AHero::InitAbilityActorInfo()
{
	AStarPlayerState* StarPS = GetPlayerState<AStarPlayerState>();
	GUARD(IsValid(StarPS),, TEXT("Player state is invalid in Hero Class"));

	AbilitySystemComponent = StarPS->GetStarASC();
	AbilitySystemComponent->InitAbilityActorInfo(StarPS, this);
	AttributeSet = StarPS->GetAttributeSet();
	Loadout = StarPS->GetLoadout();
	Loadout->OwnerCharacter = this;
}
