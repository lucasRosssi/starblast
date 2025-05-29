// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/StarCharacter.h"

#include "Components/WidgetComponent.h"

AStarCharacter::AStarCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	OverheadWidget = CreateDefaultSubobject<UWidgetComponent>("OverheadWidget");
	OverheadWidget->SetupAttachment(GetRootComponent());
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

