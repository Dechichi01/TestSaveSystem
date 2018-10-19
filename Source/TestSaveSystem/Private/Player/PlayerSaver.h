// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Saver.h"
#include "PlayerSaver.generated.h"

class AMyPlayer;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPlayerSaver : public UActorComponent, public ISaver
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerSaver();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Player")
	AMyPlayer* Player;

	// Called when the game starts
	virtual void BeginPlay() override;

public:
	virtual void Save(USaveGame* const SaveGame) const;
	virtual void Load(const USaveGame* const SaveGame) const;
};
