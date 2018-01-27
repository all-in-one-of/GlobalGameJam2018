// Fill out your copyright notice in the Description page of Project Settings.

#include "TopDownCamera.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "playerCharacter.h"
#include "Kismet/GameplayStatics.h"

ATopDownCamera::ATopDownCamera()
{
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
	// Disable controller rotation
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Attach our camera and visible object to our root component. Offset and rotate the camera.
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->bAbsoluteRotation = true;
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->TargetArmLength = targetArmLength;
	//CameraBoom->SocketOffset = offset;
	//CameraBoom->RelativeRotation = rotation;

	TopDownCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCameraComponent"));
	TopDownCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCamera->bUsePawnControlRotation = false;
	//TopDownCamera->SetRelativeLocation(offset);
	//TopDownCamera->SetRelativeRotation(rotation);
}

void ATopDownCamera::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacter::StaticClass(), foundActors);
	for (int i = 0; i < foundActors.Num(); i++)
	{
		playerReferences.Add(Cast<APlayerCharacter>(foundActors[i]));
	}
}

void ATopDownCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CameraBoom->SocketOffset = offset;
	CameraBoom->RelativeRotation = rotation;
	CameraBoom->TargetArmLength = targetArmLength;
}

// Called to bind functionality to input
void ATopDownCamera::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}
