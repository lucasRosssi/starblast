// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/LoadoutComponent.h"

#include "StarTags.h"
#include "Actors/Weapons/Weapon.h"
#include "Characters/StarCharacter.h"
#include "Starblast/StarblastMacros.h"

ULoadoutComponent::ULoadoutComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void ULoadoutComponent::EquipWeapon(AWeapon* InWeapon)
{
	GUARD(Character.IsValid(),, TEXT("Character not set!"));
	GUARD(IsValid(InWeapon),, TEXT("Invalid weapon!"));

	const FStarTags& Tags = FStarTags::Get();
	
	EquippedWeapon = InWeapon;
	EquippedWeapon->SetWeaponState(Tags.Weapon_State_Equipped);

	Character->AttachWeaponToSocket(EquippedWeapon);
	EquippedWeapon->SetOwner(Character.Get());
}

void ULoadoutComponent::BeginPlay()
{
	Super::BeginPlay();

}
