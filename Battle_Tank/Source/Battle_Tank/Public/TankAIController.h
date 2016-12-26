// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"


class UTankAimingCompnent;
/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

		UTankAimingCompnent* aim = nullptr;
		AActor* controlledTank = nullptr;
		AActor* playerTank = nullptr;
		virtual void BeginPlay()override;
		virtual void Tick(float DeltaTime)override;
		void aimAtPlayer();

	protected:

		UPROPERTY(EditDefaultsOnly,Category = "AI Control")
			float acceptanceRadius = 8000;
		
		
		
	
};
