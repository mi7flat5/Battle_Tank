// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankBarrel.h"




void UTankBarrel::elevate(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1.0f, 1.0f);
	auto elevationChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto rawElevation = RelativeRotation.Pitch + elevationChange;
	SetRelativeRotation(FRotator(FMath::Clamp(rawElevation,minElevation,maxElevation), 0, 0));
}
 