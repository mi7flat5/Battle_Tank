// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankAIController.h"



ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::getPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
		ATank* tmp = GetControlledTank();

	if (tmp)
	{
		FString tankName = tmp->GetName();
		UE_LOG(LogTemp, Warning, TEXT("AI Possessd Tank name is %s"), *tankName)
	}
	
	ATank* PlayerTank = getPlayerTank();
	if (PlayerTank)
	{
		FString tankName = PlayerTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Player Possessd Tank name (from AI) is %s"), *tankName)
	}
}

