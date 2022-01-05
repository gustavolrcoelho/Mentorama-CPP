// Fill out your copyright notice in the Description page of Project Settings.


#include "CounterComponent.h"

// Sets default values for this component's properties
UCounterComponent::UCounterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCounterComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UCounterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//UKismetSystemLibrary::PrintString(this, path);

	if (Counter <= 0x00)
	{
		Counter = 1.f;
		Seconds++;

		UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Counter: %f"), Seconds));
	}

	Counter -= DeltaTime;
}

