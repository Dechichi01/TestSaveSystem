// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Saver.generated.h"

class USaveGame;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USaver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TESTSAVESYSTEM_API ISaver
{
	GENERATED_BODY()

public:
	virtual void Save(USaveGame* const SaveGame) const = 0;
	virtual void Load(const USaveGame* const SaveGame) const = 0;	
};
