// Copyright Lucas Rossi


#include "StarAssetManager.h"
#include "StarTags.h"
#include "AbilitySystemGlobals.h"

UStarAssetManager& UStarAssetManager::Get()
{
	check(GEngine);
	
	UStarAssetManager* StarAssetManager = Cast<UStarAssetManager>(GEngine->AssetManager);
	return *StarAssetManager;
}

void UStarAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	
	FStarTags::InitializeNativeGameplayTags();

	// This is required to use Target Data!
	UAbilitySystemGlobals::Get().InitGlobalData();
}
