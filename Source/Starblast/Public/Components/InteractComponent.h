// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/StarCharacter.h"
#include "Components/ActorComponent.h"
#include "InteractComponent.generated.h"


class UGameplayAbility;
class UWidgetComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARBLAST_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInteractComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	void SetCollisionComponent(UPrimitiveComponent* Component);
	
	void Enable();
	void Disable();
	
	void Interact(AStarCharacter* Character);
	void OnInteracted(const AStarCharacter* Character);
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);
	UFUNCTION()
	void OnEndOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex
	);
	
	UPROPERTY(BlueprintReadOnly, Category="Interaction")
	TObjectPtr<UPrimitiveComponent> CollisionComponent;

	UPROPERTY(EditAnywhere, Category="Interaction")
	bool bBeginEnabled = true;
	UPROPERTY(EditAnywhere, Category="Interaction")
	bool bDisableOnInteracted = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Interaction")
	TObjectPtr<UWidgetComponent> InteractWidget;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	TSubclassOf<UGameplayAbility> InteractAbility;
private:	
	bool bEnabled = true;
};
