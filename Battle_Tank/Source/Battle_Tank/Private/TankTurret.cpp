// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankTurret.h"




void UTankTurret::rotate(float inRotation)
{
	inRotation = FMath::Clamp<float>(inRotation, -1.0f, 1.0f);
	auto yawChange = inRotation * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto rawYaw = RelativeRotation.Yaw + yawChange;
	SetRelativeRotation(FRotator(0, rawYaw,0 ));
}
