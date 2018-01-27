// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "TopDownCamera.generated.h"

/**
 * 
 */

class APlayerCharacter;

UCLASS()
class GLOBALGAMEJAM2018_API ATopDownCamera : public ACameraActor
{
	GENERATED_BODY()
	
public:
	ATopDownCamera();

	UFUNCTION(BlueprintCallable)
	void Zoom();
	UFUNCTION(BlueprintCallable)
	void Move();
	UFUNCTION(BlueprintCallable)
	float GetGreatestDistance();
	UFUNCTION(BlueprintCallable)
	FVector GetCenter();

	virtual void Tick( float DeltaTime ) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<APlayerCharacter*> playerReferences;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FVector offset;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float smoothTime = 0.5f;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float minZoom = 38.0f;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float maxZoom = 10.0f;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float zoomCorrection = 5.0f;

private:
	float deltaTime = 0.016f;
	FBoxSphereBounds bounds;
};
