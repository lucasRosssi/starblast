// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "StarPlayerState.generated.h"

class ULoadoutComponent;
class UStarAttributeSet;
class UStarAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class STARBLAST_API AStarPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AStarPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UStarAbilitySystemComponent* GetStarASC() const { return AbilitySystemComponent; }
	UStarAttributeSet* GetAttributeSet() const { return AttributeSet; }
	ULoadoutComponent* GetLoadout() const { return Loadout; }
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStarAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStarAttributeSet> AttributeSet;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<ULoadoutComponent> Loadout;
private:
	UFUNCTION()
	void OnPawnChanged(APlayerState* Player, APawn* NewPawn, APawn* OldPawn);
};
