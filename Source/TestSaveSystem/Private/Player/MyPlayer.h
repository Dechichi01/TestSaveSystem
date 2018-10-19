// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

UCLASS()
class AMyPlayer : public ACharacter
{
	GENERATED_BODY()

	friend class UPlayerSaver;

public:
	// Sets default values for this character's properties
	AMyPlayer();

protected:
	UPROPERTY(EditAnywhere, Category = "Player")
	FString PlayerName;

	UPROPERTY(EditAnywhere, Category = "Player")
	uint16 PlayerLevel;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SaveGame();
	void LoadGame();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	
};
