// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InteractComponent.h"

#include "Characters/StarCharacter.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"

UInteractComponent::UInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	AreaSphere = CreateDefaultSubobject<USphereComponent>("AreaSphere");
	AreaSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	AreaSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	InteractWidget = CreateDefaultSubobject<UWidgetComponent>("InteractWidget");
	InteractWidget->SetVisibility(false);
}

void UInteractComponent::SetRootComponent(USceneComponent* RootComponent)
{
	AreaSphere->SetupAttachment(RootComponent);
	InteractWidget->SetupAttachment(RootComponent);
}

void UInteractComponent::Enable()
{
	bEnabled = true;
	AreaSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	AreaSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &UInteractComponent::OnSphereOverlap);
	AreaSphere->OnComponentEndOverlap.AddDynamic(this, &UInteractComponent::OnSphereEndOverlap);
}

void UInteractComponent::Disable()
{
	bEnabled = false;
	AreaSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	AreaSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AreaSphere->OnComponentBeginOverlap.RemoveDynamic(this, &UInteractComponent::OnSphereOverlap);
	AreaSphere->OnComponentEndOverlap.RemoveDynamic(this, &UInteractComponent::OnSphereEndOverlap);
}


void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner() && GetOwner()->HasAuthority() && bBeginEnabled)
	{
		Enable();
	}
	else
	{
		Disable();
	}
}

void UInteractComponent::OnSphereOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	// TODO: Check if OtherActor implements "Interact" interface

	if (Cast<AStarCharacter>(OtherActor))
	{
		InteractWidget->SetVisibility(true);
	}
}

void UInteractComponent::OnSphereEndOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex
)
{
	// TODO: Check if OtherActor implements "Interact" interface

	if (Cast<AStarCharacter>(OtherActor))
	{
		InteractWidget->SetVisibility(false);
	}
}
