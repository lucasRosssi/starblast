// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StarCharacter.generated.h"

class UWidgetComponent;

UCLASS()
class STARBLAST_API AStarCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AStarCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Widget")
	TObjectPtr<UWidgetComponent> OverheadWidget;

private:	

};
