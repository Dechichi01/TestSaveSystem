// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayer.h"
#include "Components/InputComponent.h"
#include "ActorStatics.h"
#include "DebugUtils.h"

// Sets default values
AMyPlayer::AMyPlayer() : PlayerName("DefaultName"), PlayerLevel(0)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("SaveGame", IE_Pressed, this, &AMyPlayer::SaveGame);
	PlayerInputComponent->BindAction("LoadGame", IE_Pressed, this, &AMyPlayer::LoadGame);
}

void AMyPlayer::SaveGame()
{
	LogDebug("Called save game");
	UActorStatics::SaveGame(GetGameInstance());
}

void AMyPlayer::LoadGame()
{
	LogDebug("Called LOAD game");
	UActorStatics::LoadGame(GetGameInstance());
}
