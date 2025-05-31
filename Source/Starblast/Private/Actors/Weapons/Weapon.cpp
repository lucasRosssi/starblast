// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Weapons/Weapon.h"

#include "StarTags.h"
#include "AbilitySystem/StarAbilitySystemComponent.h"
#include "Characters/StarCharacter.h"
#include "Components/InteractComponent.h"
#include "Components/CapsuleComponent.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);
	WeaponMesh->SetCollisionResponseToAllChannels(ECR_Block);
	WeaponMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	InteractArea = CreateDefaultSubobject<UCapsuleComponent>("InteractArea");
	InteractArea->SetCollisionResponseToAllChannels(ECR_Ignore);
	InteractArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	InteractArea->SetupAttachment(GetRootComponent());

	InteractComponent = CreateDefaultSubobject<UInteractComponent>("InteractComponent");
	InteractComponent->SetCollisionComponent(InteractArea);
}

void AWeapon::SetWeaponState(const FGameplayTag& InStateTag)
{
	if (!InStateTag.MatchesTag(FStarTags::Get().Weapon_State))
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid Weapon State Tag: %s"), *InStateTag.ToString());
		return;
	}

	WeaponStateTag = InStateTag;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
}

UInteractComponent* AWeapon::GetInteractComponent_Implementation() const
{
	return InteractComponent;
}

UStarAbilitySystemComponent* AWeapon::GetAbilitySystemComponent()
{
	if (!OwningCharacter) return nullptr;

	if (!AbilitySystemComponent)
	{
		AbilitySystemComponent = Cast<UStarAbilitySystemComponent>(GetOwningCharacter()->GetAbilitySystemComponent());
	}

	return AbilitySystemComponent;
}
