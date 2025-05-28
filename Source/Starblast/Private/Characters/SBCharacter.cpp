// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SBCharacter.h"

#include "Components/WidgetComponent.h"

ASBCharacter::ASBCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	OverheadWidget = CreateDefaultSubobject<UWidgetComponent>("OverheadWidget");
	OverheadWidget->SetupAttachment(GetRootComponent());
}

void ASBCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASBCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASBCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

