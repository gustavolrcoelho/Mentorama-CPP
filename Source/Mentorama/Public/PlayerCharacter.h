// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/GamePlayStatics.h"
#include "MyGameModeBase.h"
#include "PlayerCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, int, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCoinChanged, int, NewBalance);

UCLASS()
class MENTORAMA_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* inputComponent) override;

	UFUNCTION(BlueprintCallable)
	void MakeAllCharactersJump();

	UFUNCTION(BlueprintCallable)
	void HandleDamage(int Damage);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowDeathFeedback();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Attack();

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCoinChanged FOnCoinChanged;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MaxHealth = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int CurrentHealth;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int CurrentCoins;

	UFUNCTION(BlueprintCallable)
	void AddCoins(int Value);
	
	UFUNCTION(BlueprintCallable)
	int CountCoins();

	UFUNCTION(BlueprintCallable)
	void RemoveCoins(int Value) { CurrentCoins -= Value;  }

	TArray<AActor*> Characters;
};
