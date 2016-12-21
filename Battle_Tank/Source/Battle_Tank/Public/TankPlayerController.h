// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"




class ATank;
class UTankAimingCompnent;
/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	
		virtual void BeginPlay()override;
		
		//if bugs, try Tick() method
		virtual void Tick(float DeltaTime)override;
		
		void aimTowardsCrosshair();
	
private:
	
		bool GetSightRayHitLocation(FVector&)const;

		bool getLookvectorHitLocation(FVector & lookAt, FVector& location)const;

		bool getLookDirection(FVector2D , FVector & )const;
		UTankAimingCompnent * aim;
		ATank* owner;
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float crosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float crosshairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float lineTraceRange = 1000000;
		
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void aimingComponentFound(UTankAimingCompnent* aimReference);
		
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank()const;
	
};
