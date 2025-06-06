// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BaseAbility.generated.h"

class AStarCharacter;
class AEnemy;
class AHero;
/**
 * 
 */
UCLASS()
class STARBLAST_API UBaseAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UBaseAbility();

protected:
	UFUNCTION(BlueprintPure, Category="Avatar", meta=(HidePin="Target", DefaultToSelf="Target"))
	AHero* GetHero();
	UFUNCTION(BlueprintPure, Category="Avatar", meta=(HidePin="Target", DefaultToSelf="Target"))
	AEnemy* GetEnemy();
	UFUNCTION(BlueprintPure, Category="Avatar", meta=(HidePin="Target", DefaultToSelf="Target"))
	AStarCharacter* GetStarCharacter();
	
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Debug")
	bool bDebugAbility = false;
	UPROPERTY(
		EditDefaultsOnly,
		BlueprintReadOnly,
		Category="Debug",
		meta=(EditCondition="bDebugAbility", EditConditionHides)
	)
	float DrawShapeDuration = 2.f;
	UPROPERTY(
		EditDefaultsOnly,
		BlueprintReadOnly,
		Category="Debug",
		meta=(EditCondition="bDebugAbility", EditConditionHides)
	)
	FColor DrawShapeColor = FColor::Green;
#endif
	
private:
	UPROPERTY()
	TObjectPtr<AHero> AvatarHero;

	UPROPERTY()
	TObjectPtr<AEnemy> AvatarEnemy;

	UPROPERTY()
	TObjectPtr<AStarCharacter> AvatarStarCharacter;
};
