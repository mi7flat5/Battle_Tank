// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

	//Max force on tracks in Newtons
	UPROPERTY(EditDefaultsOnly)
		float trackMaxDrivingForce = 400000.0f;
public:
	
	UFUNCTION(BlueprintCallable,Category = Input)
		void setThrottle(float throttle);

	
};
