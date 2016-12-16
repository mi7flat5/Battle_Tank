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
	
	if (tmp) {
		FString tankName = tmp->GetName();
		UE_LOG(LogTemp,Warning, TEXT("TankPossessd name is %s"),*tankName)
	}
}