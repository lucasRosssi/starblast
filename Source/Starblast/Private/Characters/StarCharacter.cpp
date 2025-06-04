// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/StarCharacter.h"

#include "AbilitySystem/StarAbilitySystemComponent.h"
#include "Actors/Weapons/Weapon.h"
#include "Components/LoadoutComponent.h"
#include "Components/WidgetComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Net/UnrealNetwork.h"
#include "Starblast/StarblastMacros.h"

AStarCharacter::AStarCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	OverheadWidget = CreateDefaultSubobject<UWidgetComponent>("OverheadWidget");
	OverheadWidget->SetupAttachment(GetRootComponent());
}

const USkeletalMeshSocket* AStarCharacter::GetWeaponSocket()
{
	return GetMesh()->GetSocketByName(WeaponSocketName);
}

void AStarCharacter::AttachWeaponToSocket(AWeapon* Weapon)
{
	const USkeletalMeshSocket* WeaponSocket = GetWeaponSocket();
	if (WeaponSocket)
	{
		WeaponSocket->AttachActor(Weapon, GetMesh());
	}
}

void AStarCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AStarCharacter::InitAbilityActorInfo()
{
}

void AStarCharacter::InitializeAbilities()
{
	if (!HasAuthority()) return;

	GetStarASC()->AddStartupAbilities(DefaultAbilities);
}

void AStarCharacter::InitializeAttributesAndEffects()
{
	if (DefaultAttributes) ApplyEffectToSelf(DefaultAttributes, 1.f);

	if (!DefaultEffects.IsEmpty())
	{
		for (const auto Effect : DefaultEffects)
		{
			ApplyEffectToSelf(Effect, 1.f);
		}
	}
}

void AStarCharacter::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& GameplayEffectClass, float Level) const
{
	GUARD(IsValid(GameplayEffectClass),, TEXT("Gameplay Effect Class is not valid!"));
	
	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	GUARD(IsValid(ASC),, TEXT("Ability System Component is not valid!"));

	FGameplayEffectContextHandle ContextHandle = ASC->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(
		GameplayEffectClass,
		Level,
		ContextHandle
	);
	ASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), ASC);
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

UAbilitySystemComponent* AStarCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

