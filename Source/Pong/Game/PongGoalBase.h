// Copyright (C) 2022 Jan Maślak

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PongGoalBase.generated.h"

class UBoxComponent;

UCLASS()
class PONG_API APongGoalBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APongGoalBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UBoxComponent* GoalArea;

	// Index of player who corresponds to this goal
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PlayerIndex = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
