// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/LoadoutComponent.h"

#include "StarTags.h"
#include "Actors/Weapons/Weapon.h"
#include "Characters/StarCharacter.h"
#include "Engine/SkeletalMeshSocket.h"

ULoadoutComponent::ULoadoutComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void ULoadoutComponent::EquipWeapon(AWeapon* InWeapon)
{
	if (!Character.IsValid() || InWeapon == nullptr) return;

	const FStarTags& Tags = FStarTags::Get();
	
	EquippedWeapon = InWeapon;
	EquippedWeapon->SetWeaponState(Tags.Weapon_State_Equipped);

	const USkeletalMeshSocket* WeaponSocket = Character->GetWeaponSocket();
	if (WeaponSocket)
	{
		WeaponSocket->AttachActor(EquippedWeapon, Character->GetMesh());
	}
	EquippedWeapon->SetOwner(Character.Get());
}

void ULoadoutComponent::BeginPlay()
{
	Super::BeginPlay();

}
