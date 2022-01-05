// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MentoramaHelpers.generated.h"

/**
 * 
 */
UCLASS()
class MENTORAMA_API UMentoramaHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Helpers")
	static int SumAll(TArray<int> Array);

	UFUNCTION(BlueprintCallable, Category = "Helpers")
	static int MySum(int a, int b, int c) { return a + b + c; };

	UFUNCTION(BlueprintPure, Category = "Helpers")
	static int Factorial(int Number);

	UFUNCTION(BlueprintPure, Category = "Helpers")
	static int FindFirstDivisibleNumber(int Number);

	UFUNCTION(BlueprintCallable, Category = "Helpers")
	static bool IsPrime(int Number);

	UFUNCTION(BlueprintCallable, Category = "Helpers")
	static int IsBestScore(TArray<int> Scores);

	UFUNCTION(BlueprintCallable, Category = "Helpers")
	static void PrintStringArray(TArray<FString> Array);
	
	UFUNCTION(BlueprintCallable, Category = "Helpers")
	static bool IsPalindrome(FString Word);
	
	UFUNCTION(BlueprintCallable, Category = "Helpers")
	static void ShuffleString(FString& Word);

	UFUNCTION(BlueprintCallable, Category = "Save")
	static FString GetUsernameDataPath();

	UFUNCTION(BlueprintCallable, Category = "Save")
	static void SaveUsername(FString Username);

	UFUNCTION(BlueprintPure, Category = "Save")
	static FString LoadUsername();

	//UFUNCTION(BlueprintCallable, Category = "Save")
	//static void SaveInstanceCount(int InstanceCount);

	UFUNCTION(BlueprintCallable, Category = "Save")
	static int LoadInstanceCount();	

	UFUNCTION(BlueprintCallable, Category = "Helpers")
	bool IsOdd(int Number);

	void RemoveAllWordsThatStartWith(TArray<FString>& Names, TCHAR Letter);

};
