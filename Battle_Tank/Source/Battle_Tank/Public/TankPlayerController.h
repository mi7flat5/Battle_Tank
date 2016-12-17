// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include"Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
		ATank* GetControlledTank()const;
		virtual void BeginPlay()override;
		
		//if bugs, try Tick() method
		virtual void PlayerTick(float DeltaTime)override;
		
		void aimTowardsCrosshair();

		/** What is the Player's current musical skill level? */
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			float crosshairXLocation = 0.5f;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			float crosshairYLocation = 0.33333f;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			float lineTraceRange = 1000000;
private:
	
		
		bool GetSightRayHitLocation(FVector&)const;

		bool getLookvectorHitLocation(FVector & lookAt, FHitResult & hit)const;

		bool getLookDirection(FVector2D , FVector & )const;
	
};
