// Copyright Lucas Rossi


#include "StarTags.h"
#include "GameplayTagsManager.h"
#include "NativeGameplayTags.h"

FStarTags FStarTags::GameplayTags;

const FStarTags& FStarTags::Get()
{
  if (GameplayTags.IsValid()) return GameplayTags;

  InitializeNativeGameplayTags();
  return GameplayTags;
}

void FStarTags::InitializeNativeGameplayTags()
{
  if (GameplayTags.IsValid()) return;

	/*
	 * Input Tags
	 */
  
  UE_DEFINE_GAMEPLAY_TAG_STATIC(InputTag, "Input");
  GameplayTags.InputTag = InputTag;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(InputTag_Primary, "Input.Primary");
  GameplayTags.InputTag_Primary = InputTag_Primary;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(InputTag_Secondary, "Input.Secondary");
  GameplayTags.InputTag_Secondary = InputTag_Secondary;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(InputTag_Loadout, "Input.Loadout");
  GameplayTags.InputTag_Loadout = InputTag_Loadout;
	UE_DEFINE_GAMEPLAY_TAG_STATIC(InputTag_Loadout_1, "Input.Loadout.1");
	GameplayTags.InputTag_Loadout_1 = InputTag_Loadout_1;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(InputTag_Loadout_2, "Input.Loadout.2");
  GameplayTags.InputTag_Loadout_2 = InputTag_Loadout_2;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(InputTag_Loadout_3, "Input.Loadout.3");
  GameplayTags.InputTag_Loadout_3 = InputTag_Loadout_3;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(InputTag_Loadout_4, "Input.Loadout.4");
  GameplayTags.InputTag_Loadout_4 = InputTag_Loadout_4;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(InputTag_Dodge, "Input.Dodge");
  GameplayTags.InputTag_Dodge = InputTag_Dodge;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(InputTag_Confirm, "Input.Confirm");
  GameplayTags.InputTag_Confirm = InputTag_Confirm;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(InputTag_Cancel, "Input.Cancel");
  GameplayTags.InputTag_Cancel = InputTag_Cancel;
	UE_DEFINE_GAMEPLAY_TAG_STATIC(InputTag_Interact, "Input.Interact");
	GameplayTags.InputTag_Interact = InputTag_Interact;

	/*
	 * Hero Tags
	 */
	
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Heroes, "Heroes");
  GameplayTags.Heroes = Heroes;

	/*
	 * Attribute Tags
	 */
	
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes, "Attributes");
  GameplayTags.Attributes = Attributes;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_Health, "Attributes.Health");
  GameplayTags.Attributes_Health = Attributes_Health;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_MaxHealth, "Attributes.MaxHealth");
  GameplayTags.Attributes_MaxHealth = Attributes_MaxHealth;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_HealthRegeneration, "Attributes.HealthRegeneration");
  GameplayTags.Attributes_HealthRegeneration = Attributes_HealthRegeneration;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_Stamina, "Attributes.Stamina");
  GameplayTags.Attributes_Stamina = Attributes_Stamina;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_MaxStamina, "Attributes.MaxStamina");
  GameplayTags.Attributes_MaxStamina = Attributes_MaxStamina;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_StaminaRegeneration, "Attributes.StaminaRegeneration");
  GameplayTags.Attributes_StaminaRegeneration = Attributes_StaminaRegeneration;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_Power, "Attributes.Power");
  GameplayTags.Attributes_Power = Attributes_Power;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_Armor, "Attributes.Armor");
  GameplayTags.Attributes_Armor = Attributes_Armor;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_CriticalRate, "Attributes.CriticalRate");
  GameplayTags.Attributes_CriticalRate = Attributes_CriticalRate;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_CriticalDamage, "Attributes.CriticalDamage");
  GameplayTags.Attributes_CriticalDamage = Attributes_CriticalDamage;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_WeakSpotDamage, "Attributes.WeakSpotDamage");
  GameplayTags.Attributes_WeakSpotDamage = Attributes_WeakSpotDamage;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_CooldownReduction, "Attributes.CooldownReduction");
  GameplayTags.Attributes_CooldownReduction = Attributes_CooldownReduction;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_MovementSpeed, "Attributes.MovementSpeed");
  GameplayTags.Attributes_MovementSpeed = Attributes_MovementSpeed;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_ReloadSpeed, "Attributes.ReloadSpeed");
  GameplayTags.Attributes_ReloadSpeed = Attributes_ReloadSpeed;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_FireRate, "Attributes.FireRate");
  GameplayTags.Attributes_FireRate = Attributes_FireRate;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_Accuracy, "Attributes.Accuracy");
  GameplayTags.Attributes_Accuracy = Attributes_Accuracy;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_Range, "Attributes.Range");
  GameplayTags.Attributes_Range = Attributes_Range;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_HandgunAmmo, "Attributes.HandgunAmmo");
  GameplayTags.Attributes_HandgunAmmo = Attributes_HandgunAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_MaxHandgunAmmo, "Attributes.MaxHandgunAmmo");
  GameplayTags.Attributes_MaxHandgunAmmo = Attributes_MaxHandgunAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_ShotgunAmmo, "Attributes.ShotgunAmmo");
  GameplayTags.Attributes_ShotgunAmmo = Attributes_ShotgunAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_MaxShotgunAmmo, "Attributes.MaxShotgunAmmo");
  GameplayTags.Attributes_MaxShotgunAmmo = Attributes_MaxShotgunAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_AssaultRifleAmmo, "Attributes.AssaultRifleAmmo");
  GameplayTags.Attributes_AssaultRifleAmmo = Attributes_AssaultRifleAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_MaxAssaultRifleAmmo, "Attributes.MaxAssaultRifleAmmo");
  GameplayTags.Attributes_MaxAssaultRifleAmmo = Attributes_MaxAssaultRifleAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_SniperAmmo, "Attributes.SniperAmmo");
  GameplayTags.Attributes_SniperAmmo = Attributes_SniperAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_MaxSniperAmmo, "Attributes.MaxSniperAmmo");
  GameplayTags.Attributes_MaxSniperAmmo = Attributes_MaxSniperAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_SMGAmmo, "Attributes.SMGAmmo");
  GameplayTags.Attributes_SMGAmmo = Attributes_SMGAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_MaxSMGAmmo, "Attributes.MaxSMGAmmo");
  GameplayTags.Attributes_MaxSMGAmmo = Attributes_MaxSMGAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_ExplosiveAmmo, "Attributes.ExplosiveAmmo");
  GameplayTags.Attributes_ExplosiveAmmo = Attributes_ExplosiveAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_MaxExplosiveAmmo, "Attributes.MaxExplosiveAmmo");
  GameplayTags.Attributes_MaxExplosiveAmmo = Attributes_MaxExplosiveAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_SpecialAmmo, "Attributes.SpecialAmmo");
  GameplayTags.Attributes_SpecialAmmo = Attributes_SpecialAmmo;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Attributes_MaxSpecialAmmo, "Attributes.MaxSpecialAmmo");
  GameplayTags.Attributes_MaxSpecialAmmo = Attributes_MaxSpecialAmmo;

	/*
	 * Meta Attributes
	 */

	UE_DEFINE_GAMEPLAY_TAG_STATIC(Meta, "Meta");
	GameplayTags.Meta = Meta;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Meta_Damage, "Meta.Damage");
  GameplayTags.Meta_Damage = Meta_Damage;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Meta_Heal, "Meta.Heal");
  GameplayTags.Meta_Heal = Meta_Heal;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Meta_XP, "Meta.XP");
  GameplayTags.Meta_XP = Meta_XP;
  UE_DEFINE_GAMEPLAY_TAG_STATIC(Meta_Force, "Meta.Force");
  GameplayTags.Meta_Force = Meta_Force;

	/*
	 * Weapon Tags
	 */
	
	UE_DEFINE_GAMEPLAY_TAG_STATIC(Weapon, "Weapon");
	GameplayTags.Weapon = Weapon;
	UE_DEFINE_GAMEPLAY_TAG_STATIC(Weapon_State, "Weapon.State");
	GameplayTags.Weapon_State = Weapon_State;
	UE_DEFINE_GAMEPLAY_TAG_STATIC(Weapon_State_Default, "Weapon.State.Default");
	GameplayTags.Weapon_State_Default = Weapon_State_Default;
	UE_DEFINE_GAMEPLAY_TAG_STATIC(Weapon_State_Equipped, "Weapon.State.Equipped");
	GameplayTags.Weapon_State_Equipped = Weapon_State_Equipped;
	UE_DEFINE_GAMEPLAY_TAG_STATIC(Weapon_State_Dropped, "Weapon.State.Dropped");
	GameplayTags.Weapon_State_Dropped = Weapon_State_Dropped;
	
  /*
   * Map of Tags to their children
   */

  const TArray LoadoutInputTags(
    {
      GameplayTags.InputTag_Loadout_1,
      GameplayTags.InputTag_Loadout_2,
      GameplayTags.InputTag_Loadout_3,
      GameplayTags.InputTag_Loadout_4
    }
  );

  GameplayTags.ParentsToChildren.Add(GameplayTags.InputTag_Loadout, LoadoutInputTags);
  
  GameplayTags.bIsValid = true;
}
