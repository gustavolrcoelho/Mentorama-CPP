// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyGameModeBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameOver);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameWon);

UCLASS()
class MENTORAMA_API AMyGameModeBase : public AGameMode
{
	GENERATED_BODY()

	bool HasGameEnded = false;
	int ObjectiveCounter = 0;

public:
	UFUNCTION(BlueprintCallable)
	void SetPlayerIsDead();

	UFUNCTION(BlueprintCallable)
	void RegisterObjective();

	UFUNCTION(BlueprintCallable)
	void UnregisterObjective();

	UPROPERTY(BlueprintAssignable)
	FOnGameOver OnGameOver;
	
	UPROPERTY(BlueprintAssignable)
	FOnGameWon OnGameWon;
};
