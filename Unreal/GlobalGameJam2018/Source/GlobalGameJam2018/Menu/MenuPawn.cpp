// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuPawn.h"

#include "Engine.h"


// Sets default values
AMenuPawn::AMenuPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (GEngine && GEngine->GetWorld())
	{
		UGameInstance* BasicGameInstance = Cast<UGameInstance>(GEngine->GetWorld()->GetGameInstance());

		GameInstance = Cast<UMainGameInstance>(BasicGameInstance);
	}

}

// Called when the game starts or when spawned
void AMenuPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMenuPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMenuPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("A_Button", IE_Pressed, this, &AMenuPawn::StartPressed);

}

void AMenuPawn::SetId(int idp)
{
	Id = idp; // ye idk
}

void AMenuPawn::StartPressed()
{
	GameInstance->StartButtonPressed(Id);
}

