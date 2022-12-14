// Copyright (C) 2022 Jan Maślak

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PongBallBase.generated.h"

UCLASS()
class PONG_API APongBallBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APongBallBase();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveSpeed = 100.0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
