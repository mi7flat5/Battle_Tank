// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingCompnent;
class UTankBarrel;
class AProjectile;
UCLASS()
class BATTLE_TANK_API ATank : public APawn
{
	GENERATED_BODY()

	UTankBarrel* barrel;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float fireingVelocity = 4000;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
public:
	ATank();
	void aimAt(FVector)const;

	UFUNCTION(BlueprintCallable, Category = Set)
		void setBarrellReference(UTankBarrel* inBarrel);

	UFUNCTION(BlueprintCallable, Category = Set)
		void setTurretReference(UTankTurret* inTurret);
	
	UFUNCTION(BlueprintCallable, Category = "Firing")
		void fireTank();
protected:
	UTankAimingCompnent* tankAimingComponent = nullptr;
};
