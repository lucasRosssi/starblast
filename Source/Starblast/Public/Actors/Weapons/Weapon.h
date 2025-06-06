// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "Interfaces/InteractableInterface.h"
#include "Weapon.generated.h"

class AStarCharacter;
class UStarAbilitySystemComponent;
class UInteractComponent;
class UCapsuleComponent;

UCLASS()
class STARBLAST_API AWeapon : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	AWeapon();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void SetWeaponState(const FGameplayTag& InStateTag);

protected:
	virtual void BeginPlay() override;

	// START Interactable Interface
	virtual UInteractComponent* GetInteractComponent_Implementation() const override;
	// END Interactable Interface

	AStarCharacter* GetOwningCharacter() const { return OwningCharacter; }
	UStarAbilitySystemComponent* GetAbilitySystemComponent();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Interaction")
	TObjectPtr<UCapsuleComponent> InteractArea;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapon Properties")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Interaction")
	TObjectPtr<UInteractComponent> InteractComponent;

	UPROPERTY(
		ReplicatedUsing=OnRep_WeaponStateTag,
		VisibleAnywhere,
		BlueprintReadOnly,
		Category="Weapon Properties"
	)
	FGameplayTag WeaponStateTag;
private:
	UPROPERTY()
	AStarCharacter* OwningCharacter;
	
	UPROPERTY()
	UStarAbilitySystemComponent* AbilitySystemComponent;

	UFUNCTION()
	void OnRep_WeaponStateTag();

};
