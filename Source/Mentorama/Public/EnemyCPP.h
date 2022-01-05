// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MentoramaHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/SphereComponent.h"
#include "MyGameModeBase.h"
#include "PlayerCharacter.h"

#include "EnemyCPP.generated.h"

UCLASS()
class MENTORAMA_API AEnemyCPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Flags")
	float Health;

	UPROPERTY (BlueprintReadWrite, EditAnywhere, Category="Flags")
	float TimePassed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Flags")
	float TimeToTurn;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Flags")
	float MovementSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Flags")
	FVector MovementDirection;

	UFUNCTION(BlueprintCallable, Category = "Helpers")
	float EnemySum(float a, float b, float c);

	UFUNCTION(BlueprintCallable, Category = "Helpers")
	void TakeDamageCPP (float Damage);

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	USphereComponent* DamageSphereComponent;

	UFUNCTION(BlueprintCallable)
	void HandleSphereHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
