// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Weapons/Weapon.h"

#include "Components/InteractComponent.h"
#include "Components/SphereComponent.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);
	WeaponMesh->SetCollisionResponseToAllChannels(ECR_Block);
	WeaponMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	InteractComponent = CreateDefaultSubobject<UInteractComponent>("InteractComponent");
	InteractComponent->SetRootComponent(GetRootComponent());
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}
