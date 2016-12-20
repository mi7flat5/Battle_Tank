// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()


		ATank* controlledTank = nullptr;
		ATank* playerTank = nullptr;
		virtual void BeginPlay()override;
		virtual void Tick(float DeltaTime)override;
		
		UPROPERTY(EditDefaultsOnly,Category = "AI Control")
			float acceptanceRadius = 300;
		
		void aimAtPlayer();
		
	
};
