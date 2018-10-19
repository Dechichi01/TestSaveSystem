// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TestSaveGame.generated.h"

#define PLAYER_CATEGORY "Player"
/**
 * 
 */
UCLASS()
class TESTSAVESYSTEM_API UTestSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = PLAYER_CATEGORY)
	FString PlayerName;

	UPROPERTY(VisibleAnywhere, Category = PLAYER_CATEGORY)
	uint16 PlayerLevel;
};
