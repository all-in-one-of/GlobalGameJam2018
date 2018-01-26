// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */

USTRUCT()
struct FPlayerConnection 
{
	GENERATED_BODY()

	UPROPERTY()
	bool IsConnected;

	UPROPERTY()
	unsigned int PlayerId;

};

UCLASS()
class GLOBALGAMEJAM2018_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMainGameInstance();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Levels")
	TArray<FName> LevelArray;

	UPROPERTY()
	FPlayerConnection Players[4];

	void StartButtonPressed(unsigned int id);

private:
	void SavePlayerData();
	void LoadPlayerData();

private:
	unsigned int CurrentLevelIndex;

public:
	UFUNCTION(BlueprintCallable, Category = "Levels")
	void ChangeCurrentLevel(FName LevelName, bool ResetPlayerData);
	
	UFUNCTION(BlueprintCallable, Category = "Levels")
	void ChangeCurrentLevelToNext();
};
