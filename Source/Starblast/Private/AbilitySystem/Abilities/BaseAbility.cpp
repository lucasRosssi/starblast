// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/BaseAbility.h"

#include "Characters/Enemy.h"
#include "Characters/Hero.h"

AHero* UBaseAbility::GetHero()
{
	if (AvatarHero == nullptr)
	{
		AvatarHero = Cast<AHero>(GetAvatarActorFromActorInfo());
	}

	return AvatarHero;
}

AEnemy* UBaseAbility::GetEnemy()
{
	if (AvatarEnemy == nullptr)
	{
		AvatarEnemy = Cast<AEnemy>(GetAvatarActorFromActorInfo());
	}

	return AvatarEnemy;
}

AStarCharacter* UBaseAbility::GetStarCharacter()
{
	if (AvatarStarCharacter == nullptr)
	{
		AvatarStarCharacter = Cast<AStarCharacter>(GetAvatarActorFromActorInfo());
	}

	return AvatarStarCharacter;
}
