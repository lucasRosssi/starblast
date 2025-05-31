// Copyright Lucas Rossi

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "StarAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class STARBLAST_API UStarAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static UStarAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
