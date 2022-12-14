// Copyright (C) 2022 Jan Maślak


#include "PongGameModeBase.h"

#include "PongBallBase.h"
#include "PongPlayerBase.h"
#include "PongWidgetBase.h"
#include "Kismet/GameplayStatics.h"

void APongGameModeBase::BeginPlay()
{
	if (GameWidgetClass)
	{
		GameWidget = Cast<UPongWidgetBase>(CreateWidget(GetWorld(), GameWidgetClass));
		
		if (GameWidget)
		{
			UpdateWidgetText();
			GameWidget->AddToViewport();
		}
	}
}

void APongGameModeBase::UpdateWidgetText()
{
	GameWidget->SetScoreText(Player1Score, Player2Score);
}

void APongGameModeBase::AdvanceTimer()
{
	CountdownSeconds--;
	GameWidget->SetTimerText(CountdownSeconds);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("TIMER")));

	if (CountdownSeconds < 0)
	{
		FinishGame();
	}
}

void APongGameModeBase::BeginGame()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("BEGIN GAME")));

	CountdownSeconds = MaxSeconds;
	
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &APongGameModeBase::AdvanceTimer, 1.0f, true);
}

void APongGameModeBase::FinishGame()
{
	UGameplayStatics::OpenLevel(this, FName("AfterMatch"));
}

void APongGameModeBase::SetMaxScore(int32 _MaxScore)
{
	MaxScore = _MaxScore;
}

void APongGameModeBase::SetCountdown(int32 _TimeInSeconds)
{
	MaxSeconds = _TimeInSeconds;
}

void APongGameModeBase::PlayerScored(int32 PlayerIndex)
{
	// Update player's score
	if (PlayerIndex == 0)
	{
		Player2Score++;
	}
	else
	{
		Player1Score++;
	}
	
	UpdateWidgetText();

	if (Player1Score == MaxScore || Player2Score == MaxScore)
	{
		FinishGame();
	}
	
	// Reset ball position
	TArray<AActor*> Balls;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APongBallBase::StaticClass(), Balls);

	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%d"), Balls.Num()));
	
	if (Balls.Num() > 0)
	{
		AActor* Ball = Balls[0];
		TArray<AActor*> Players;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APongPlayerBase::StaticClass(), Players);
		FVector LoserPos = Players[0]->GetActorLocation();
		Ball->SetActorLocation(FVector(0,0,0));
	}
}

