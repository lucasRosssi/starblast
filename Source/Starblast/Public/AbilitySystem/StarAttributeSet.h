// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "StarAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

#define REGISTER_ATTRIBUTE(ClassName, PropertyName) \
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_##PropertyName, Category="Attributes") \
	FGameplayAttributeData PropertyName; \
	ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	UFUNCTION() \
	void OnRep_##PropertyName(const FGameplayAttributeData& Old##PropertyName) \
	{ \
		GAMEPLAYATTRIBUTE_REPNOTIFY(ClassName, PropertyName, Old##PropertyName); \
	}

#define REGISTER_META_ATTRIBUTE(ClassName, PropertyName) \
	UPROPERTY(BlueprintReadOnly, Category="Meta Attributes") \
	FGameplayAttributeData PropertyName; \
	ATTRIBUTE_ACCESSORS(ClassName, PropertyName)
/**
 * 
 */
UCLASS()
class STARBLAST_API UStarAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UStarAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category="Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, Health)
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, Health, OldHealth);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category="Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, MaxHealth)
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, MaxHealth, OldMaxHealth);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category="Attributes")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, HealthRegeneration)
	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, HealthRegeneration, OldHealthRegeneration);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category="Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, Stamina)
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, Stamina, OldStamina);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category="Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, MaxStamina)
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, MaxStamina, OldMaxStamina);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_StaminaRegeneration, Category="Attributes")
	FGameplayAttributeData StaminaRegeneration;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, StaminaRegeneration)
	UFUNCTION()
	void OnRep_StaminaRegeneration(const FGameplayAttributeData& OldStaminaRegeneration)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, StaminaRegeneration, OldStaminaRegeneration);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Power, Category="Attributes")
	FGameplayAttributeData Power;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, Power)
	UFUNCTION()
	void OnRep_Power(const FGameplayAttributeData& OldPower)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, Power, OldPower);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category="Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, Armor)
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, Armor, OldArmor);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalRate, Category="Attributes")
	FGameplayAttributeData CriticalRate;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, CriticalRate)
	UFUNCTION()
	void OnRep_CriticalRate(const FGameplayAttributeData& OldCriticalRate)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, CriticalRate, OldCriticalRate);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalDamage, Category="Attributes")
	FGameplayAttributeData CriticalDamage;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, CriticalDamage)
	UFUNCTION()
	void OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, CriticalDamage, OldCriticalDamage);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_WeakSpotDamage, Category="Attributes")
	FGameplayAttributeData WeakSpotDamage;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, WeakSpotDamage)
	UFUNCTION()
	void OnRep_WeakSpotDamage(const FGameplayAttributeData& OldWeakSpotDamage)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, WeakSpotDamage, OldWeakSpotDamage);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CooldownReduction, Category="Attributes")
	FGameplayAttributeData CooldownReduction;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, CooldownReduction)
	UFUNCTION()
	void OnRep_CooldownReduction(const FGameplayAttributeData& OldCooldownReduction)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, CooldownReduction, OldCooldownReduction);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MovementSpeed, Category="Attributes")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, MovementSpeed)
	UFUNCTION()
	void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, MovementSpeed, OldMovementSpeed);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ReloadSpeed, Category="Attributes")
	FGameplayAttributeData ReloadSpeed;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, ReloadSpeed)
	UFUNCTION()
	void OnRep_ReloadSpeed(const FGameplayAttributeData& OldReloadSpeed)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, ReloadSpeed, OldReloadSpeed);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_FireRate, Category="Attributes")
	FGameplayAttributeData FireRate;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, FireRate)
	UFUNCTION()
	void OnRep_FireRate(const FGameplayAttributeData& OldFireRate)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, FireRate, OldFireRate);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Accuracy, Category="Attributes")
	FGameplayAttributeData Accuracy;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, Accuracy)
	UFUNCTION()
	void OnRep_Accuracy(const FGameplayAttributeData& OldAccuracy)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, Accuracy, OldAccuracy);
	}

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Range, Category="Attributes")
	FGameplayAttributeData Range;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, Range)
	UFUNCTION()
	void OnRep_Range(const FGameplayAttributeData& OldRange)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UStarAttributeSet, Range, OldRange);
	}

	UPROPERTY(BlueprintReadOnly, Category="Meta Attributes")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, Damage)
	
	UPROPERTY(BlueprintReadOnly, Category="Meta Attributes")
	FGameplayAttributeData Heal;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, Heal)
	
	UPROPERTY(BlueprintReadOnly, Category="Meta Attributes")
	FGameplayAttributeData XP;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, XP)
	
	UPROPERTY(BlueprintReadOnly, Category="Meta Attributes")
	FGameplayAttributeData Force;
	ATTRIBUTE_ACCESSORS(UStarAttributeSet, Force)

protected:

private:
};
