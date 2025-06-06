// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/StarAnimInstance.h"

#include "Characters/StarCharacter.h"

void UStarAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	StarCharacter = Cast<AStarCharacter>(TryGetPawnOwner());
}

void UStarAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (StarCharacter == nullptr)
	{
		StarCharacter = Cast<AStarCharacter>(TryGetPawnOwner());
	}

	if (StarCharacter == nullptr) return;

	bWeaponEquipped = StarCharacter->IsWeaponEquipped();
}
