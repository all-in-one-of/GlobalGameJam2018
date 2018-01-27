// Fill out your copyright notice in the Description page of Project Settings.

#include "TopDownCamera.h"
#include "Camera/CameraComponent.h"
#include "playerCharacter.h"

ATopDownCamera::ATopDownCamera()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATopDownCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	deltaTime = DeltaTime;

	if (playerReferences.Num() < 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get players."));
		return;
	}

	Move();
	Zoom();
}

void ATopDownCamera::Zoom()
{
	float newZoom = FMath::Lerp(maxZoom, minZoom, GetGreatestDistance() / zoomCorrection);
	float newFOV = FMath::Lerp(GetCameraComponent()->FieldOfView, newZoom, deltaTime);
	GetCameraComponent()->SetFieldOfView(newFOV);
}

void ATopDownCamera::Move()
{
	FVector center = GetCenter();
	FVector position = center + offset;
	FVector smoothedPosition = FMath::Lerp(GetActorLocation(), position, smoothTime);
	SetActorLocation(smoothedPosition);
}

float ATopDownCamera::GetGreatestDistance()
{
	float distance = playerReferences[0]->GetActorLocation().X;

	for (int i = 0; i < playerReferences.Num(); i++)
	{
		if (playerReferences[i]->GetActorLocation().X > distance)
		{
			distance = playerReferences[i]->GetActorLocation().X;
		}
	}

	return distance;
}

FVector ATopDownCamera::GetCenter()
{
	if (playerReferences.Num() == 1)
	{
		return playerReferences[0]->GetActorLocation();
	}

	return FVector();
}
