// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorStatics.h"
#include "../Game/MyGameInstance.h"
#include "GameSaver.h"
#include "DebugUtils.h"

void UActorStatics::SaveGame(const UGameInstance* GameInstance)
{
	const UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
	if (ENSURE(MyGameInstance))
	{
		MyGameInstance->GetGameSaver()->Save();
	}
}

void UActorStatics::LoadGame(const UGameInstance* GameInstance)
{
	const UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
	if (ENSURE(MyGameInstance))
	{
		MyGameInstance->GetGameSaver()->Load();
	}
}

void UActorStatics::RegisterForSave(const UGameInstance * GameInstance, ISaver * Saver)
{
	const UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
	if (ENSURE(MyGameInstance))
	{
		MyGameInstance->GetGameSaver()->RegisterSaver(Saver);
	}
}

void UActorStatics::UnregisterFromSave(const UGameInstance * GameInstance, ISaver * Saver)
{
	const UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
	if (ENSURE(MyGameInstance))
	{
		MyGameInstance->GetGameSaver()->DeregisterSaver(Saver);
	}
}
