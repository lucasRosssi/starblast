// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StarCharacter.generated.h"

class ULoadoutComponent;
class IInteractableInterface;
class AWeapon;
class UStarAttributeSet;
class UStarAbilitySystemComponent;
class UWidgetComponent;

UCLASS()
class STARBLAST_API AStarCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AStarCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostInitializeComponents() override;

	UStarAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystemComponent; }
	UStarAttributeSet* GetAttributeSet() const { return AttributeSet; }

	const USkeletalMeshSocket* GetWeaponSocket();
	void AttachWeaponToSocket(AWeapon* Weapon);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStarAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStarAttributeSet> AttributeSet;

	TObjectPtr<ULoadoutComponent> Loadout;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Widget")
	TObjectPtr<UWidgetComponent> OverheadWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon")
	FName WeaponSocketName = FName("RightHandSocket");

private:

};
