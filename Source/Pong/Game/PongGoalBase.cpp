// Copyright (C) 2022 Jan Maślak


#include "PongGoalBase.h"

#include "PongBallBase.h"
#include "PongGameModeBase.h"
#include "Components/BoxComponent.h"

// Sets default values
APongGoalBase::APongGoalBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	// Create mesh component and enable physics for it
	GoalArea = CreateDefaultSubobject<UBoxComponent>("GoalArea");
}

// Called when the game starts or when spawned
void APongGoalBase::BeginPlay()
{
	Super::BeginPlay();

	GoalArea->OnComponentBeginOverlap.AddDynamic(this, &APongGoalBase::OverlapBegin);
}

// Called every frame
void APongGoalBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APongGoalBase::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APongBallBase>(OtherActor) != nullptr)
	{
		APongGameModeBase* GameMode = Cast<APongGameModeBase>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->PlayerScored(PlayerIndex);
		}
	}
}
