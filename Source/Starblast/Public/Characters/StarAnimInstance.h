// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "StarAnimInstance.generated.h"

class AStarCharacter;
/**
 * 
 */
UCLASS()
class STARBLAST_API UStarAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(BlueprintReadOnly)
	AStarCharacter* StarCharacter = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	bool bWeaponEquipped = false;
	
private:
	
};
