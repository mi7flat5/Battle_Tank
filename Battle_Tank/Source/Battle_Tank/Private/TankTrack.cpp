// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankTrack.h"




void UTankTrack::setThrottle(float throttle)
{
	

	auto forceApplied = GetForwardVector()* throttle* trackMaxDrivingForce;
	
	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	//forceApplied.Z = 0;

	auto forceLocation = GetSocketLocation(FName("Hitch"));
	auto tankRotation = tankRoot->GetComponentRotation();
	tankRotation.Roll = FMath::Clamp<float>(tankRotation.Roll, -3.0f,3.0f);
	tankRotation.Pitch = FMath::Clamp<float>(tankRotation.Pitch, -20.0f, 20.0f);;
	tankRoot->SetWorldRotation(FQuat(tankRotation));
	tankRoot->AddForceAtLocation(forceApplied,forceLocation);
}
