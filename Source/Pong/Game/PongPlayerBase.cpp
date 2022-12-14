// Copyright (C) 2022 Jan Maślak


#include "PongPlayerBase.h"

// Sets default values
APongPlayerBase::APongPlayerBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create mesh component and enable physics for it
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetSimulatePhysics(true);
	Mesh->SetMassOverrideInKg(NAME_None, 1, true);
}

// Called when the game starts or when spawned
void APongPlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APongPlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Zeroize velocity in case ball hits us sideways
	Mesh->SetAllPhysicsLinearVelocity(FVector(0, 0, 0), false);
}

// Called to bind functionality to input
void APongPlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Moves paddle up or down
void APongPlayerBase::Move(const float Value)
{
	const FVector Up = FVector(1, 0, 0) * MoveSpeed * Value;
	Mesh->AddLocalOffset(Up, false, nullptr, ETeleportType::None);
	// Mesh->AddImpulse(Up);
}

void APongPlayerBase::SendBall()
{
	
}
