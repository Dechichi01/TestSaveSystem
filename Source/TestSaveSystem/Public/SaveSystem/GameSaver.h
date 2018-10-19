// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "GameSaver.generated.h"

class ISaver;

/**
 * GameSaver: used for centralized saving. Probably should be a singleton instance
 * Workflow:
	. Register ISavers by using RegisterSaver
	. ISaver::Save(USaveGame) will be called during save games
	. ISaver::Load(USaveGame) will be called during load game

   Issues: ISaver needs to cast USaveGame to the desired type
 */

UCLASS(config = Game, transient, BlueprintType, Blueprintable)
class TESTSAVESYSTEM_API UGameSaver final : public UObject
{
	GENERATED_BODY()

private:
	class TArray<ISaver*> Savers;

	UPROPERTY(EditDefaultsOnly, Category = "Save")
	FString SaveSlotName;

	UPROPERTY(EditDefaultsOnly, Category = "Save")
	uint32 UserIndex;

public:
	UGameSaver();
	~UGameSaver();

	FORCEINLINE void RegisterSaver(ISaver* Saver);
	FORCEINLINE bool DeregisterSaver(ISaver* Saver);
	FORCEINLINE void CleanSavers();

	void Save();

	void Load();

	void DeleteSave();
};
