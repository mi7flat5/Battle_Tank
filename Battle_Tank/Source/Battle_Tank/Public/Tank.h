// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingCompnent;
class UTankMovementComponent;
class UTankBarrel;
class AProjectile;
class UTankTrack;

UCLASS()
class BATTLE_TANK_API ATank : public APawn
{
	GENERATED_BODY()

	UTankBarrel* barrel;

	virtual void BeginPlay() override;
	

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float fireingVelocity = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float reloadTime = 3;

	double lastFiredTime;
	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
public:
	ATank();
	void aimAt(FVector)const;

	UFUNCTION(BlueprintCallable, Category = Setup)
		void setBarrellReference(UTankBarrel* inBarrel);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void setTurretReference(UTankTurret* inTurret);
	
	UFUNCTION(BlueprintCallable, Category = Firing)
		void fireTank();
protected:
	UTankAimingCompnent* tankAimingComponent = nullptr;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Setup)
	//UTankMovementComponent* tankMovementComponent = nullptr;
};
