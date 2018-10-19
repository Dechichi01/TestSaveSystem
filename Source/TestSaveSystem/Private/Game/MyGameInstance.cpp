// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance(const FObjectInitializer& ObjectInitializer) {
	Super(ObjectInitializer);
	GameSaver = CreateDefaultSubobject<UGameSaver>(TEXT("Game Saver"));
}