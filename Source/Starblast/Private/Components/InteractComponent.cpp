// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InteractComponent.h"

#include "Characters/StarCharacter.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Net/UnrealNetwork.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Starblast/StarblastMacros.h"

UInteractComponent::UInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	InteractWidget = CreateDefaultSubobject<UWidgetComponent>("InteractWidget");
	InteractWidget->SetIsReplicated(false);
	InteractWidget->SetVisibility(false);
}

void UInteractComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	
}

void UInteractComponent::SetCollisionComponent(UPrimitiveComponent* Component)
{
	CollisionComponent = Component;
	InteractWidget->SetupAttachment(Component);
}

void UInteractComponent::Enable()
{
	GUARD(CollisionComponent,, TEXT("CollisionComponent not defined!"), *GetOwner()->GetName());
	
	bEnabled = true;
	CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &UInteractComponent::OnOverlap);
	CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &UInteractComponent::OnEndOverlap);
}

void UInteractComponent::Disable()
{
	GUARD(CollisionComponent,, TEXT("CollisionComponent not defined!"), *GetOwner()->GetName());
	
	bEnabled = false;
	CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CollisionComponent->OnComponentBeginOverlap.RemoveDynamic(this, &UInteractComponent::OnOverlap);
	CollisionComponent->OnComponentEndOverlap.RemoveDynamic(this, &UInteractComponent::OnEndOverlap);
	InteractWidget->SetVisibility(false);
}

void UInteractComponent::Interact(AStarCharacter* Character)
{
	GUARD(IsValid(InteractAbility),, TEXT("Interact Ability not set!"));
	
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character);
	FGameplayAbilitySpec InteractAbilitySpec = FGameplayAbilitySpec(InteractAbility, 1);
	FGameplayEventData Data = FGameplayEventData();
	Data.Instigator = Character;
	Data.Target = GetOwner();
	ASC->GiveAbilityAndActivateOnce(InteractAbilitySpec, &Data);
	
	OnInteracted(Character);
}

void UInteractComponent::OnInteracted(const AStarCharacter* Character)
{
	if (bDisableOnInteracted)
	{
		Disable();
	}
	else
	{
		if (Character->IsLocallyControlled())
		{
			InteractWidget->SetVisibility(false);
		}
	}
}


void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();

	if (bBeginEnabled)
	{
		Enable();
	}
	else
	{
		Disable();
	}
}

void UInteractComponent::OnOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	// TODO: Check if OtherActor implements "Interact" interface

	if (AStarCharacter* StarCharacter = Cast<AStarCharacter>(OtherActor))
	{
		StarCharacter->SetInteractComponentInRange(this);
	
		if (StarCharacter->IsLocallyControlled())
		{
			InteractWidget->SetVisibility(true);
		}
	}
}

void UInteractComponent::OnEndOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex
)
{
	// TODO: Check if OtherActor implements "Interact" interface

	if (AStarCharacter* StarCharacter = Cast<AStarCharacter>(OtherActor))
	{
		StarCharacter->SetInteractComponentInRange(nullptr);
		
		if (StarCharacter->IsLocallyControlled())
		{
			InteractWidget->SetVisibility(false);
		}
	}
}
