// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "StarCharacter.generated.h"

class UInteractComponent;
class UGameplayAbility;
class UGameplayEffect;
class ULoadoutComponent;
class IInteractableInterface;
class AWeapon;
class UStarAttributeSet;
class UStarAbilitySystemComponent;
class UWidgetComponent;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnASCRegistered, UStarAbilitySystemComponent*);

UCLASS()
class STARBLAST_API AStarCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AStarCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UStarAbilitySystemComponent* GetStarASC() const { return AbilitySystemComponent; }
	UStarAttributeSet* GetAttributeSet() const { return AttributeSet; }
	UFUNCTION(BlueprintPure)
	virtual ULoadoutComponent* GetLoadout();

	UInteractComponent* GetInteractComponentInRange() const { return InteractComponentInRange; }
	void SetInteractComponentInRange(UInteractComponent* InComponent) { InteractComponentInRange = InComponent; }

	UFUNCTION(BlueprintPure, Category="Weapon")
	const USkeletalMeshSocket* GetWeaponSocket();
	UFUNCTION(BlueprintCallable)
	void AttachWeaponToSocket(AWeapon* Weapon);
	bool IsWeaponEquipped();

	FOnASCRegistered ASCRegisteredDelegate;

protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo();
	virtual void InitializeAbilities();
	virtual void InitializeAttributesAndEffects();

	void ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& GameplayEffectClass, float Level) const;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStarAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStarAttributeSet> AttributeSet;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<ULoadoutComponent> Loadout;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Widget")
	TObjectPtr<UWidgetComponent> OverheadWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character Defaults|Weapon")
	FName WeaponSocketName = FName("RightHandSocket");

	UPROPERTY(EditDefaultsOnly, Category = "Character Defaults|Ability System")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Defaults|Ability System")
	TSubclassOf<UGameplayEffect> DefaultAttributes;
	UPROPERTY(EditDefaultsOnly, Category="Character Defaults|Ability System")
	TArray<TSubclassOf<UGameplayEffect>> DefaultEffects;

private:
	UPROPERTY()
	UInteractComponent* InteractComponentInRange = nullptr;

	FGameplayTag CombatStateTag = FGameplayTag();
};
