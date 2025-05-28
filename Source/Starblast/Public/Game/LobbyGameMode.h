// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SBGameMode.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class STARBLAST_API ALobbyGameMode : public ASBGameMode
{
	GENERATED_BODY()

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
