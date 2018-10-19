// Fill out your copyright notice in the Description page of Project Settings.

#include "GameSaver.h"
#include "Saver.h"
#include "TestSaveGame.h"
#include "GameFramework/SaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "DebugUtils.h"

#define DEFAULT_SAVE_FILE_PATH TEXT("DefaultSaveSlot")

UGameSaver::UGameSaver() : Savers(), SaveSlotName(DEFAULT_SAVE_FILE_PATH), UserIndex(0)
{}

UGameSaver::~UGameSaver()
{}

FORCEINLINE void UGameSaver::RegisterSaver(ISaver * Saver)
{
	Savers.Add(Saver);
}

FORCEINLINE bool UGameSaver::DeregisterSaver(ISaver * Saver)
{
	return Savers.RemoveSwap(Saver) > 0;
}

FORCEINLINE void UGameSaver::CleanSavers()
{
	Savers.Reset();
}

void UGameSaver::Save()
{
	LogDebug("Starting to save with %d Savers!!", Savers.Num());
	UTestSaveGame* SaveGameInstance = Cast<UTestSaveGame>(UGameplayStatics::CreateSaveGameObject(UTestSaveGame::StaticClass()));
	for (uint16 i = 0; i < Savers.Num(); i++)
	{
		const ISaver* saver = Savers[i];
		if (saver)
		{
			saver->Save(SaveGameInstance);
		}
	}

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveSlotName, UserIndex);

	LogDebug("Finish saving!");
}

void UGameSaver::Load()
{
	LogDebug("LOADING with %d Savers!!", Savers.Num());
	UTestSaveGame* LoadGameInstance = Cast<UTestSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
	
	for (uint16 i = 0; i < Savers.Num(); i++)
	{
		const ISaver* saver = Savers[i];
		if (saver)
		{
			saver->Load(LoadGameInstance);
		}
	}

	LogDebug("Finish LOADING!");
}

void UGameSaver::DeleteSave()
{
	UGameplayStatics::DeleteGameInSlot(SaveSlotName, UserIndex);
}
