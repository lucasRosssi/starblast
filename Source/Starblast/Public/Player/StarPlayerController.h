// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/PlayerController.h"
#include "StarPlayerController.generated.h"

class AHero;
class UInteractComponent;
class UStarAbilitySystemComponent;
class UStarInputConfig;
class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class STARBLAST_API AStarPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

protected:
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	TObjectPtr<UStarInputConfig> InputConfig;
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> MainContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> TargetingActorMoveAction;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> ConfirmAction;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> CancelAction;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> InteractAction;

private:
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);

	void ConfirmPressed();
	void CancelPressed();

	void InteractPressed();

	UFUNCTION(Server, Reliable)
	void ServerInteract(UInteractComponent* InteractComponent);
	
	UStarAbilitySystemComponent* GetASC();

	AHero* GetHeroPawn();

	UPROPERTY()
	TObjectPtr<UStarAbilitySystemComponent> StarASC;

	UPROPERTY()
	TObjectPtr<AHero> HeroPawn;
};
