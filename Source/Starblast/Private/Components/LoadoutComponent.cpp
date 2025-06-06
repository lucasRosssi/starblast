// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/LoadoutComponent.h"

#include "StarTags.h"
#include "Actors/Weapons/Weapon.h"
#include "Characters/StarCharacter.h"
#include "Net/UnrealNetwork.h"
#include "Starblast/StarblastMacros.h"

ULoadoutComponent::ULoadoutComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	SetIsReplicated(true);
}

void ULoadoutComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ULoadoutComponent, EquippedWeapon);
}

void ULoadoutComponent::EquipWeapon(AWeapon* InWeapon)
{
	GUARD(IsValid(OwnerCharacter),, TEXT("Character not set!"));
	GUARD(IsValid(InWeapon),, TEXT("Invalid weapon!"));

	const FStarTags& StarTags = FStarTags::Get();
	
	EquippedWeapon = InWeapon;
	EquippedWeapon->SetWeaponState(StarTags.Weapon_State_Equipped);

	OwnerCharacter->AttachWeaponToSocket(EquippedWeapon);
	EquippedWeapon->SetOwner(OwnerCharacter);
}

void ULoadoutComponent::BeginPlay()
{
	Super::BeginPlay();

}
