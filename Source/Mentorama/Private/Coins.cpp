// Fill out your copyright notice in the Description page of Project Settings.


#include "Coins.h"

// Sets default values
ACoins::ACoins()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GatheringColliderComponent = CreateDefaultSubobject<USphereComponent>("Collider Sphere");
	RootComponent = GatheringColliderComponent;
}

// Called when the game starts or when spawned
void ACoins::BeginPlay()
{
	Super::BeginPlay();
	GatheringColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoins::HandleGathering);
	
	auto* GameMode = GetWorld()->GetAuthGameMode<AMyGameModeBase>();

	if (IsValid(GameMode))
	{
		GameMode->RegisterObjective();
	}
}

// Called every frame
void ACoins::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoins::HandleGathering(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	auto* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);

	if (IsValid(PlayerCharacter))
	{
		PlayerCharacter->AddCoins(1);

		if (PlayerCharacter->CurrentHealth < 100)
		{
			PlayerCharacter->HandleDamage(-20);
		}
		//UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Coins: %d"), PlayerCharacter->CountCoins()));
		
		auto* GameMode = GetWorld()->GetAuthGameMode<AMyGameModeBase>();

		if (IsValid(GameMode))
		{
			GameMode->UnregisterObjective();
		}
		
		Destroy();
	}

}
