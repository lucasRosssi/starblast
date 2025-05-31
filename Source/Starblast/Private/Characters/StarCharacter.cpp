// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/StarCharacter.h"

#include "Components/LoadoutComponent.h"
#include "Components/WidgetComponent.h"
#include "Net/UnrealNetwork.h"

AStarCharacter::AStarCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	OverheadWidget = CreateDefaultSubobject<UWidgetComponent>("OverheadWidget");
	OverheadWidget->SetupAttachment(GetRootComponent());

	Loadout = CreateDefaultSubobject<ULoadoutComponent>("Loadout");
}

const USkeletalMeshSocket* AStarCharacter::GetWeaponSocket()
{
	return GetMesh()->GetSocketByName(WeaponSocketName);
}

void AStarCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AStarCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStarCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AStarCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}

void AStarCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (Loadout)
	{
		Loadout->Character = this;
	}
}

