// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankPlayerController.h"
#include"TankAimingCompnent.h"




void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController begin play."))

	owner = GetPawn();
	if (ensure(owner)) 
	{
		aim = owner->FindComponentByClass<UTankAimingCompnent>();
		if(ensure(aim))
		aimingComponentFound(aim);
		else UE_LOG(LogTemp, Warning, TEXT("No Aiming component found in TankPlayerController Begin Play"))
		FString tankName = owner->GetName();
		UE_LOG(LogTemp,Warning, TEXT("TankPossessd name is %s"),*tankName)
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	aimTowardsCrosshair();
}

void ATankPlayerController::aimTowardsCrosshair()
{
	if (ensure(owner && aim))
	{
		FVector hitLocation;
		bool gotHit = GetSightRayHitLocation(hitLocation);
		if (gotHit)
		{
			aim->aimAt(hitLocation);
		}
		//else aim->aimAt(hitLocation);//TODO figure out why the course tank does this, may be changed in later videos.
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& location) const
{
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	FVector2D screenLocation = FVector2D(viewportSizeX* crosshairXLocation,viewportSizeY* crosshairYLocation);
	FVector lookDir;
	
	if (getLookDirection(screenLocation, lookDir))
	{
		
		return getLookvectorHitLocation(lookDir, location);
		
	}
	
	return false;
}

bool ATankPlayerController::getLookvectorHitLocation(FVector& lookAt, FVector &location)const
{
	FHitResult hit;
	FVector startLoc = PlayerCameraManager->GetCameraLocation();
	FVector endLoc = startLoc + lookAt*lineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel(hit, startLoc, endLoc, ECollisionChannel::ECC_Visibility))
	{
		location = hit.Location;
		return true;
	}
	location = FVector(0);
	return false;
}

bool ATankPlayerController::getLookDirection(FVector2D screenloc, FVector &lookDir)const
{	
	FVector throwAwayForArgs;
	return DeprojectScreenPositionToWorld(screenloc.X, screenloc.Y, throwAwayForArgs, lookDir);
	
}