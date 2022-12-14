// Copyright (C) 2022 Jan Maślak

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PongPlayerBase.generated.h"

UCLASS()
class PONG_API APongPlayerBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APongPlayerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Variables

	// 3D mesh for player's paddle
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* Mesh;

	// How fast should the player move
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveSpeed = 100.0;

	void SendBall();

public:
	UFUNCTION(BlueprintCallable, Category="Pong")
	void Move(float Value);
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
