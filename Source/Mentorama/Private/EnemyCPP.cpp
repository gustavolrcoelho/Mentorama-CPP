// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCPP.h"

// Sets default values
AEnemyCPP::AEnemyCPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DamageSphereComponent = CreateDefaultSubobject<USphereComponent>("DamageSphere");

	DamageSphereComponent->SetupAttachment(RootComponent);
	DamageSphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemyCPP::HandleSphereHit);
	
	Health = 100;
	TimeToTurn = 5;
	MovementSpeed = 1;
	MovementDirection = {0, 1, 0};
}

// Called when the game starts or when spawned
void AEnemyCPP::BeginPlay()
{
	Super::BeginPlay();

	//UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Sum: %f"), UMentoramaHelpers::Sum(4, 5, 6)));
	auto* GameMode = GetWorld()->GetAuthGameMode<AMyGameModeBase>();

	if (IsValid(GameMode))
	{
		GameMode->RegisterObjective();
	}
	//UMentoramaHelpers::SaveUsername(TEXT("Gustavo"));
	//UMentoramaHelpers::SaveUsername("Gustavo");
}

// Called every frame
void AEnemyCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimePassed += DeltaTime;

	if (TimePassed > TimeToTurn)
	{
		MovementDirection *= -1;
		TimePassed = 0;
	}

	AddMovementInput(MovementDirection, MovementSpeed);
}

// Called to bind functionality to input
void AEnemyCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

float AEnemyCPP::EnemySum(float a, float b, float c)
{
	return a + b + c;
}

void AEnemyCPP::TakeDamageCPP(float Damage)
{
	if (Health <= 0)
	{
		auto* GameMode = GetWorld()->GetAuthGameMode<AMyGameModeBase>();

		if (IsValid(GameMode))
		{
			GameMode->UnregisterObjective();
		}

		Destroy();
	}

	Health -= Damage;
}

void AEnemyCPP::HandleSphereHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
								UPrimitiveComponent* OtherComp,			  int32 OtherBodyIndex,
								bool bFromSweep,						  const FHitResult& SweepResult)
{
	auto* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);

	if (IsValid(PlayerCharacter))
	{
		PlayerCharacter->HandleDamage(20);
	}

}

