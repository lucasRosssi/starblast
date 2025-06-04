// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/StarCharacter.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class STARBLAST_API AEnemy : public AStarCharacter
{
	GENERATED_BODY()

public:
	AEnemy();
	
protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;
private:
};
