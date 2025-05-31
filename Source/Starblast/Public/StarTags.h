// Copyright Lucas Rossi

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AuraGameplayTags
 *
 * Singleton containing native Gameplay Tags
 */

struct FStarTags
{
public:
	bool IsValid() const { return bIsValid; }
  static const FStarTags& Get();
  static void InitializeNativeGameplayTags();

	/* INPUTS */

	FGameplayTag InputTag;
	FGameplayTag InputTag_Primary;
	FGameplayTag InputTag_Secondary;
	FGameplayTag InputTag_Loadout;
	FGameplayTag InputTag_Loadout_1;
	FGameplayTag InputTag_Loadout_2;
	FGameplayTag InputTag_Loadout_3;
	FGameplayTag InputTag_Loadout_4;
	FGameplayTag InputTag_Dodge;

	FGameplayTag InputTag_Confirm;
	FGameplayTag InputTag_Cancel;

	FGameplayTag InputTag_Interact;

  FGameplayTag Heroes;
	
	FGameplayTag Attributes;

	FGameplayTag Attributes_Health;
	FGameplayTag Attributes_MaxHealth;
	FGameplayTag Attributes_HealthRegeneration;
	FGameplayTag Attributes_Stamina;
	FGameplayTag Attributes_MaxStamina;
	FGameplayTag Attributes_StaminaRegeneration;
	FGameplayTag Attributes_Power;
	FGameplayTag Attributes_Armor;
	FGameplayTag Attributes_CriticalRate;
	FGameplayTag Attributes_CriticalDamage;
	FGameplayTag Attributes_WeakSpotDamage;
	FGameplayTag Attributes_CooldownReduction;
	FGameplayTag Attributes_MovementSpeed;
	FGameplayTag Attributes_ReloadSpeed;
	FGameplayTag Attributes_FireRate;
	FGameplayTag Attributes_Accuracy;
	FGameplayTag Attributes_Range;

	FGameplayTag Attributes_HandgunAmmo;
	FGameplayTag Attributes_MaxHandgunAmmo;
	FGameplayTag Attributes_ShotgunAmmo;
	FGameplayTag Attributes_MaxShotgunAmmo;
	FGameplayTag Attributes_AssaultRifleAmmo;
	FGameplayTag Attributes_MaxAssaultRifleAmmo;
	FGameplayTag Attributes_SniperAmmo;
	FGameplayTag Attributes_MaxSniperAmmo;
	FGameplayTag Attributes_SMGAmmo;
	FGameplayTag Attributes_MaxSMGAmmo;
	FGameplayTag Attributes_ExplosiveAmmo;
	FGameplayTag Attributes_MaxExplosiveAmmo;
	FGameplayTag Attributes_SpecialAmmo;
	FGameplayTag Attributes_MaxSpecialAmmo;

	FGameplayTag Meta;
	FGameplayTag Meta_Damage;
  FGameplayTag Meta_Heal;
	FGameplayTag Meta_XP;
	FGameplayTag Meta_Force;

	FGameplayTag Weapon;
	FGameplayTag Weapon_State;
	FGameplayTag Weapon_State_Default;
	FGameplayTag Weapon_State_Equipped;
	FGameplayTag Weapon_State_Dropped;


	TMap<FGameplayTag, TArray<FGameplayTag>> ParentsToChildren;

private:
	static FStarTags GameplayTags;

	bool bIsValid = false;
};
