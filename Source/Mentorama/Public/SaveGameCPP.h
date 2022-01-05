// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "HAL/Platform.h"
#include "SaveGameCPP.generated.h"

/**
 * 
 */
UCLASS()
class MENTORAMA_API USaveGameCPP : public USaveGame
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Player Info")
	FString UserName;

	UPROPERTY(BlueprintReadWrite, Category = "Player Info")
	int InstanceCount;

public:
	UFUNCTION(BlueprintCallable, Category = "Username")
	void SetUserName(FString NewUserName) { UserName = NewUserName; };
	
	UFUNCTION(BlueprintCallable, Category = "Username")
	FString GetUserName() { return UserName; };

	UFUNCTION(BlueprintCallable, Category = "Instance")
	void SetInstanceCount(int NewInstanceCount) { InstanceCount = NewInstanceCount; };

	UFUNCTION(BlueprintCallable, Category = "Instance")
	int GetInstanceCount() { return InstanceCount; };
};
