// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

class UGameSaver;
/**
 * 
 */
UCLASS()
class UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;

	FORCEINLINE UGameSaver* GetGameSaver() const { return GameSaver; };

private:
	UPROPERTY(VisibleAnywhere, Category = "Save Game")
	UGameSaver* GameSaver;
};
