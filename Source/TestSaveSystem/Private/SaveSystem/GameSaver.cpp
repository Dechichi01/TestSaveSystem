// Fill out your copyright notice in the Description page of Project Settings.

#include "GameSaver.h"
#include "Saver.h"
#include "GameFramework/SaveGame.h"
#include "Kismet/GameplayStatics.h"

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
	USaveGame* SaveGameInstance = UGameplayStatics::CreateSaveGameObject(USaveGame::StaticClass());
	for (uint16 i = 0; i < Savers.Num(); i++)
	{
		ISaver* saver = Savers[i];
		if (saver)
		{
			saver->Save(SaveGameInstance);
		}
	}

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveSlotName, UserIndex);
}

void UGameSaver::Load()
{
	USaveGame* LoadGameInstance = UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex);
	
	for (uint16 i = 0; i < Savers.Num(); i++)
	{
		ISaver* saver = Savers[i];
		if (saver)
		{
			saver->Load(LoadGameInstance);
		}
	}
}

void UGameSaver::DeleteSave()
{
	UGameplayStatics::DeleteGameInSlot(SaveSlotName, UserIndex);
}
