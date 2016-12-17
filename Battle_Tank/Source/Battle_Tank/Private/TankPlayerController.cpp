// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankPlayerController.h"

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController begin play."))
	
	ATank* tmp = GetControlledTank();
	if (tmp) 
	{
		FString tankName = tmp->GetName();
		UE_LOG(LogTemp,Warning, TEXT("TankPossessd name is %s"),*tankName)
	}
}

void ATankPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	aimTowardsCrosshair();
}

void ATankPlayerController::aimTowardsCrosshair()
{
	if (!GetControlledTank())
		return;
	FVector hitLocation;
	if (GetSightRayHitLocation(hitLocation))
	{
		GetControlledTank()->aimAt(hitLocation);
	}
	
		
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& location) const
{
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	FVector2D screenLocation = FVector2D(viewportSizeX* crosshairXLocation,viewportSizeY* crosshairYLocation);
	FVector lookAt;
	
	if (getLookDirection(screenLocation, lookAt))
	{
		FHitResult hit;
		if (getLookvectorHitLocation(lookAt, hit)) 
		{
			location = hit.Location;
			return true;
		}
	}
	
	return false;
}

bool ATankPlayerController::getLookvectorHitLocation(FVector& lookAt, FHitResult& hit)const
{
	FCollisionQueryParams traceparams = FCollisionQueryParams(FName(TEXT("")), false, GetOwner());
	FCollisionResponseParams responsParams = FCollisionResponseParams();
	FVector startLoc = PlayerCameraManager->GetCameraLocation();
	FVector endLoc = startLoc + lookAt*lineTraceRange;
	return GetWorld()->LineTraceSingleByChannel(hit, startLoc, endLoc, ECollisionChannel::ECC_Visibility);
}

bool ATankPlayerController::getLookDirection(FVector2D screenloc, FVector &lookDir)const
{
	FVector throwAwayForArgs;
	return DeprojectScreenPositionToWorld(screenloc.X, screenloc.Y, throwAwayForArgs, lookDir);
	
}