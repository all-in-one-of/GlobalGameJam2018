// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include <assert.h> 

#include "MainGameInstance.h"

UMainGameInstance::UMainGameInstance() {
	CurrentLevelIndex = 0;
}

void UMainGameInstance::ChangeCurrentLevel(FName LevelName, bool ResetPlayerData) {
	CurrentLevelIndex = 0;

	for (int i = 0; i < LevelArray.Num(); i++) {
		if (LevelArray[i] == LevelName) {
			CurrentLevelIndex = 0;
		}
	}

	if (!ResetPlayerData)
		SavePlayerData();

	UGameplayStatics::OpenLevel((UObject*)this, LevelName);

	if (!ResetPlayerData)
		LoadPlayerData();

}

void UMainGameInstance::ChangeCurrentLevelToNext() {
	if (LevelArray.Num() == 0) {

		assert("LevelArray is empty.");
	}

	CurrentLevelIndex++;

	// LAST LEVEL DETECTION
	if ((int)CurrentLevelIndex >= LevelArray.Num()) {
		// If last level is exceeded, wrap to zero
		CurrentLevelIndex = 0;
	}

	SavePlayerData();

	UGameplayStatics::OpenLevel((UObject*)this, LevelArray[CurrentLevelIndex]);

	LoadPlayerData();

}

///////////////////////////////////////////////////////////////////////////////////////////

void UMainGameInstance::SavePlayerData() {

}

void UMainGameInstance::LoadPlayerData() {

}