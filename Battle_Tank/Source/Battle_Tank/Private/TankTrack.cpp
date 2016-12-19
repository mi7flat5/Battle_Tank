// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankTrack.h"




void UTankTrack::setThrottle(float throttle)
{
	auto name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *name, throttle)

	auto forceApplied = GetForwardVector()* throttle* trackMaxDrivingForce;
	auto forceLocation = GetComponentLocation();
	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied,forceLocation);
}
