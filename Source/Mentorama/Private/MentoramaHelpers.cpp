// Fill out your copyright notice in the Description page of Project Settings.


#include "MentoramaHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGameCPP.h"

int UMentoramaHelpers::Factorial(int Number)
{
	unsigned long int factorial = 1;

	if (Number == 0 || Number == 1)
		return 1;
	else
		while (Number > 1) {
			factorial *= Number;
			Number--;
		}
	return factorial;
}

int UMentoramaHelpers::FindFirstDivisibleNumber(int Number)
{
	int Result = 2;

	//Trava a UE
	/*do {
		if (Number % Result == 0)
			return Result;
		
		Result += 2;
	} while (true);*/


	do {
		if (Result % 2 == 0) {
			Result++;
			continue;
		}

		if (Number % Result == 0)
			break;
		else
			Result++;
	} while (Result < Number);

	return Result;
}

bool UMentoramaHelpers::IsPrime(int Number)
{
	bool Ans = true;

	if (Number <= 0)
		Ans = false;
	else if (Number == 1 || Number == 2)
		Ans = true;
	else
		for (int Divisor = 2; Divisor <= Number / 2; Divisor++)
			if (Number % Divisor == 0)
				Ans = false;
	return Ans;
}

int UMentoramaHelpers::IsBestScore(TArray<int> Scores)
{
	int Best = INT_MIN; //INT_MIN = Smallest value possible for an integer, -2147483647

	for (int i = 0; i < Scores.Num(); i++) {
		if (Scores[i] > Best) {
			Best = Scores[i];
		}
	}
	return Best;
}

void UMentoramaHelpers::PrintStringArray(TArray<FString> Array)
{
	for (int i = 0; i < Array.Num(); i++) {
		/*FString Temp = Array[i];
		UKismetSystemLibrary::PrintString(Temp);*/
		UE_LOG(LogTemp, Display, TEXT("%s"), *Array[i]);
	}
}

bool UMentoramaHelpers::IsPalindrome(FString Word)
{
	if (!Word.Len()) {
		return false;
	}

	bool IsPalindrome = true;

	for (int i = 0, j = Word.Len() - 1; i <= Word.Len() / 2; i++, j--) {
		if (Word[i] != Word[j]) {
			IsPalindrome = false;
			break;
		}
		else {
			IsPalindrome = true;
		}
	}

	return IsPalindrome;
}

void UMentoramaHelpers::ShuffleString(FString& Word)
{
	if (Word.Len()) {

		FString Helper = Word;
		TArray<int> Position;
		int Index = 0;

		//Starts an array with all the valid positions
		for (int i = 0; i < Word.Len(); i++) {
			Position.Add(i);
		}

		//Iterates through the lenght of the word
		for (int j = 0; j < Word.Len(); j++) {
			//If the number of valid positions is greater than 0, sorts a number 
			if (Position.Num() > 0) {
				Index = FMath::RandRange(0, Word.Len() - 1);

				//If the position array contains that position still, insert the letter into that position and removes the position from the array
				if (Position.Contains(Index)) {
					Word[Index] = Helper[j];
					Position.Remove(Index);
				}
				else {
					//If the position is no longer available, decreases iterator to stay in the same letter and tries again with a new position
					j--;
				}
			}
		}
	}
}

int UMentoramaHelpers::SumAll(TArray<int> Array) {
	int Sum = 0;

	for (int i = 0; i < Array.Num(); i++)
		Sum += Array[i];

	return Sum;
}

bool UMentoramaHelpers::IsOdd(int Number) {
	if (Number % 2 == 0)
		return true;
	else
		return false;
}

FString UMentoramaHelpers::GetUsernameDataPath()
{
	FString path = FPaths::GeneratedConfigDir() + FString("username.data");

	return path;
}

/*DEPRECATED*/;
//void UMentoramaHelpers::SaveUsername(FString Username)
//{
//	FFileHelper::SaveStringToFile(Username, *GetUsernameDataPath());
//}
// 
//FString UMentoramaHelpers::LoadUsername()
//{
//	TArray<FString> Result;
//
//	if (FFileHelper::LoadANSITextFileToStrings(*GetUsernameDataPath(), NULL, Result))
//	{
//		return Result[0];
//	}
//	else
//	{
//		return "None";
//	}
//}

void UMentoramaHelpers::SaveUsername(FString Username)
{
	USaveGameCPP *SaveGame = Cast<USaveGameCPP>(UGameplayStatics::LoadGameFromSlot(TEXT("username"), 0));
	
	if (!SaveGame)
	{
		SaveGame = Cast<USaveGameCPP>(UGameplayStatics::CreateSaveGameObject(USaveGameCPP::StaticClass()));
		SaveGame->SetInstanceCount(0);
	}

	if(SaveGame)
	{
		int NewInstanceCount = LoadInstanceCount();

		SaveGame->SetUserName(Username);
		SaveGame->SetInstanceCount(++NewInstanceCount);

		UGameplayStatics::SaveGameToSlot(SaveGame, TEXT("username"), 0);
	}
}

FString UMentoramaHelpers::LoadUsername()
{
	USaveGame *SaveGame = Cast<USaveGameCPP>(UGameplayStatics::LoadGameFromSlot(TEXT("username"), 0));

	if (const auto UserNameSave = Cast<USaveGameCPP>(SaveGame))
	{
		return UserNameSave->GetUserName();
	}
	else
	{
		return "None";
	}
}

//void UMentoramaHelpers::SaveInstanceCount(int InstanceCount)
//{
//}
//
int UMentoramaHelpers::LoadInstanceCount()
{
	USaveGame *SaveGame = Cast<USaveGameCPP>(UGameplayStatics::LoadGameFromSlot(TEXT("username"), 0));

	if (const auto UserNameSave = Cast<USaveGameCPP>(SaveGame))
	{
		return UserNameSave->GetInstanceCount();
	}
	else
	{
		return 0;
	}
}
