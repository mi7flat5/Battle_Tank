// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingCompnent.generated.h"


UENUM()
enum class EFireingState : uint8
{
	LOCKED,
	AIMING,
	RELOADING
};
class UTankBarrel;
class UTankTurret;
class AProjectile;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankAimingCompnent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	//UTankAimingCompnent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	void aimAt(FVector);
	
	// Called every frame
	UFUNCTION(BlueprintCallable, Category = Firing)
		void fire();

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float fireingVelocity = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float reloadTime = 3;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void initialize(UTankBarrel * inBarrel, UTankTurret * inTurret);

	
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "State")
		EFireingState fireingState = EFireingState::LOCKED;
	
private:
	UTankBarrel* barrel;
	UTankTurret* turret;
	FVector aimDir;
	double lastFiredTime;
	void moveBarrel(FVector dir)const;
};
