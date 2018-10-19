// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerSaver.h"
#include "TestSaveGame.h"
#include "MyPlayer.h"


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
	ensure(Player);
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

