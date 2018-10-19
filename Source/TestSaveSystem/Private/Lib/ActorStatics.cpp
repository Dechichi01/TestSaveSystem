// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorStatics.h"
#include "MyGameInstance.h"
#include "GameSaver.h"
#include "DebugUtils.h"

void UActorStatics::SaveGame(const UGameInstance* const GameInstance)
{
	const UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
	if (ENSURE(MyGameInstance))
	{
		MyGameInstance->GetGameSaver()->Save();
	}
}

void UActorStatics::LoadGame(const UGameInstance* const GameInstance)
{
	const UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
	if (ENSURE(MyGameInstance))
	{
		MyGameInstance->GetGameSaver()->Load();
	}
}
