// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingCompnent;
class UTankBarrel;

UCLASS()
class BATTLE_TANK_API ATank : public APawn
{
	GENERATED_BODY()
		

	// Sets default values for this pawn's properties
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
public:
	ATank();
	void aimAt(FVector)const;

	UFUNCTION(BlueprintCallable, Category = Set)
	void setBarrellReference(UTankBarrel* inBarrel);

	UFUNCTION(BlueprintCallable, Category = Set)
	void setTurretReference(UTankTurret* inTurret);

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float fireingVelocity = 8000;
	

protected:
	UTankAimingCompnent* tankAimingComponent = nullptr;
};
