// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LoadoutComponent.generated.h"


class AWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARBLAST_API ULoadoutComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULoadoutComponent();
	friend class AStarCharacter;

	UFUNCTION(BlueprintCallable)
	void EquipWeapon(AWeapon* InWeapon);
protected:
	virtual void BeginPlay() override;

private:
	TWeakObjectPtr<AStarCharacter> Character;

	UPROPERTY()
	AWeapon* EquippedWeapon = nullptr;
		
};
