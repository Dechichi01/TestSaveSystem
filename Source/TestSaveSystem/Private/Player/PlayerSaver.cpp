// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerSaver.h"
#include "TestSaveGame.h"
#include "MyPlayer.h"
#include "DebugUtils.h"
#include "ActorStatics.h"


// Sets default values for this component's properties
UPlayerSaver::UPlayerSaver()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UPlayerSaver::BeginPlay()
{
	UActorComponent::BeginPlay();

	Player = Cast<AMyPlayer>(GetOwner());
	if (ENSURE(Player))
	{
		UActorStatics::RegisterForSave(Player->GetGameInstance(), this);
	}
}

void UPlayerSaver::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (ENSURE(Player))
	{
		UActorStatics::UnregisterFromSave(Player->GetGameInstance(), this);
	}
}

void UPlayerSaver::Save(USaveGame * const SaveGame) const
{
	UTestSaveGame* const TestSave = Cast<UTestSaveGame>(SaveGame);
	if (!ensure(Player) || !ensure(TestSave)) 
	{
		return;
	}

	TestSave->PlayerName = Player->PlayerName;
	TestSave->PlayerLevel = Player->PlayerLevel;
}

void UPlayerSaver::Load(const USaveGame * const SaveGame) const
{
	const UTestSaveGame* const TestSave = Cast<UTestSaveGame>(SaveGame);
	if (!ensure(Player) || !ensure(TestSave))
	{
		return;
	}

	Player->PlayerName = TestSave->PlayerName;
	Player->PlayerLevel = TestSave->PlayerLevel;
}

