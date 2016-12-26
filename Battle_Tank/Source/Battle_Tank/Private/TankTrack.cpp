// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankTrack.h"




UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UTankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	

}

void UTankTrack::applySidewaysForce()
{
	// Work-out the required acceleration this frame to correct
	auto SlippageSpeed = FMath::Clamp<float>(FVector::DotProduct(GetRightVector(), GetComponentVelocity()),-1,1);
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	// Calculate and apply sideways (F = m a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Two tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::setThrottle(float throttle)
{
	currentThrottle = FMath::Clamp<float>(currentThrottle + throttle,-1,1);
}

void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * currentThrottle * trackMaxDrivingForce;
	UE_LOG(LogTemp,Warning,TEXT("Force Applied is: %f"), currentThrottle * trackMaxDrivingForce)
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTrack();
	applySidewaysForce();
	currentThrottle = 0;
	
}
