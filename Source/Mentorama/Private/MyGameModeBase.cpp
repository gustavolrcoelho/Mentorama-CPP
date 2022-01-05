// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

void AMyGameModeBase::SetPlayerIsDead()
{
	OnGameOver.Broadcast();
}

void AMyGameModeBase::RegisterObjective()
{
	ObjectiveCounter++;
}

void AMyGameModeBase::UnregisterObjective()
{
	if (HasGameEnded)
	{
		return;
	}

	ObjectiveCounter--;

	if (ObjectiveCounter <= 0)
	{
		OnGameWon.Broadcast();
		HasGameEnded = true;
	}
}
