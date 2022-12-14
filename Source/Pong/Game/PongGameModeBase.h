// Copyright (C) 2022 Jan Maślak

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PongGameModeBase.generated.h"

class UPongWidgetBase;
/**
 * 
 */
UCLASS()
class PONG_API APongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;
	
protected:
	int32 Player1Score = 0;
	int32 Player2Score = 0;

	int32 MaxScore = 3;
	int32 MaxSeconds = 60;

	int32 CountdownSeconds = 60;

	FTimerHandle CountdownTimerHandle;

	// Widget variables
	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf<class UUserWidget> GameWidgetClass;

	UPROPERTY()
	UPongWidgetBase* GameWidget;

	void UpdateWidgetText();
	void AdvanceTimer();
public:
	void PlayerScored(int32 PlayerIndex);
	UFUNCTION(BlueprintCallable)
	void BeginGame();
	UFUNCTION(BlueprintCallable)
	void FinishGame();

	UFUNCTION(BlueprintCallable)
	void SetMaxScore(int32 _MaxScore);
	UFUNCTION(BlueprintCallable)
	void SetCountdown(int32 _TimeInSeconds);
};
