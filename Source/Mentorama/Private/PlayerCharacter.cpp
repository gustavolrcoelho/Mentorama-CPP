// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentHealth = MaxHealth;
	CurrentCoins = 0;
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(this, ACharacter::StaticClass(), Characters);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* inputComponent)
{
	Super::SetupPlayerInputComponent(inputComponent);
	inputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &APlayerCharacter::Attack);
	//inputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &APlayerCharacter::MakeAllCharactersJump);
}

void APlayerCharacter::MakeAllCharactersJump()
{

	for (AActor* Character : Characters) {
		Cast<ACharacter>(Character)->Jump();
	}
}

void APlayerCharacter::HandleDamage(int Damage)
{
	CurrentHealth -= Damage;
	OnHealthChanged.Broadcast(CurrentHealth);

	if (CurrentHealth <= 0)
	{
		ShowDeathFeedback();

		auto *GameMode = GetWorld()->GetAuthGameMode<AMyGameModeBase>();

		if (IsValid(GameMode))
		{
			GameMode->SetPlayerIsDead();
		}
		SetLifeSpan(1);
	}

}

void APlayerCharacter::AddCoins(int Value)
{
	CurrentCoins += Value;
	FOnCoinChanged.Broadcast(CurrentCoins);
}

int APlayerCharacter::CountCoins()
{
	return CurrentCoins;
}

void APlayerCharacter::Attack_Implementation()
{
	//HandleDamage(10);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
}

