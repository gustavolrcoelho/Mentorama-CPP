// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObjectExample.h"

void UMyObjectExample::PostInitProperties()
{
	Super::PostInitProperties();
	//UE_LOG(LogTemp, Display, TEXT("%s PostInitProperties"), GetName());
}

void UMyObjectExample::BeginDestroy()
{
	Super::BeginDestroy();
	//UE_LOG(LogTemp, Display, TEXT("%s BeginDestroy"), GetName());
}
