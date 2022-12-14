// Copyright (C) 2022 Jan Maślak

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PongWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API UPongWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetScoreText(int32 Player1Score, int32 Player2Score);
	
	UFUNCTION(BlueprintImplementableEvent)
	void SetTimerText(int32 SecondsLeft);
};
