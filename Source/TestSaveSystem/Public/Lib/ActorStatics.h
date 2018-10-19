// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActorStatics.generated.h"

class UGameInstance;
class ISaver;

/**
 * 
 */
UCLASS()
class TESTSAVESYSTEM_API UActorStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Save Game")
	static void SaveGame(const UGameInstance* GameInstance);

	UFUNCTION(BlueprintCallable, Category = "Save Game")
	static void LoadGame(const UGameInstance* GameInstance);

	static void RegisterForSave(const UGameInstance* GameInstance, ISaver* Saver);

	static void UnregisterFromSave(const UGameInstance* GameInstance, ISaver* Saver);
};
