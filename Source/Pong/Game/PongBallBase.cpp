// Copyright (C) 2022 Jan Maślak


#include "PongBallBase.h"

// Sets default values
APongBallBase::APongBallBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create mesh component and enable physics for it
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetSimulatePhysics(true);
	Mesh->SetMassOverrideInKg(NAME_None, 1, true);

	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void APongBallBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APongBallBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Normalize horizontal move speed.
	FVector Velocity = Mesh->GetPhysicsLinearVelocity(NAME_None);
	float Direction = Velocity.GetComponentForAxis(EAxis::Type::Y);
	if (Direction > 0)
	{
		Velocity.SetComponentForAxis(EAxis::Type::Y, MoveSpeed);
	}
	else
	{
		Velocity.SetComponentForAxis(EAxis::Type::Y, -MoveSpeed);
	}
	Mesh->SetPhysicsLinearVelocity(Velocity);
}

