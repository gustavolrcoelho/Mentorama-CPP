// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObjectExample.generated.h"

/**
 * 
 */
UCLASS()
class MENTORAMA_API UMyObjectExample : public UObject
{
	GENERATED_BODY()

	virtual void PostInitProperties() override;

	virtual void BeginDestroy() override;

};
