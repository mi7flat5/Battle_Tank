// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,Category = Setup)
		float maxDegreesPerSecond = 10.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float maxElevation = 40.0f;
	
	UPROPERTY(EditAnywhere, Category = Setup)
		float minElevation = 0.0f;
public:
	void elevate(float);
};
