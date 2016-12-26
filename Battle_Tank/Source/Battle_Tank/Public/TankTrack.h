// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
		UTankTrack();
	virtual void BeginPlay()override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)override;

	void applySidewaysForce();
	

	//Max force on tracks in Newtons
	UPROPERTY(EditDefaultsOnly)
		float trackMaxDrivingForce = 400000;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
public:
	
	UFUNCTION(BlueprintCallable,Category = Input)
		void setThrottle(float throttle);

	void DriveTrack();

	float currentThrottle = 0;


	
};
