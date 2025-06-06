// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/StarCharacter.h"
#include "Hero.generated.h"

/**
 * 
 */
UCLASS()
class STARBLAST_API AHero : public AStarCharacter
{
	GENERATED_BODY()

public:
	AHero();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	virtual ULoadoutComponent* GetLoadout() override;
	
protected:
	virtual void InitAbilityActorInfo() override;
	
private:
};
