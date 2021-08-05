// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
     
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the 4 letter word!")); // Magic Number Remove!
    PrintLine(TEXT("Press enter to continue..."));

    InitGame();
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
     //Move outside this function.
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You have won!"));
    }
    else 
    {
        PrintLine(TEXT("You have Lost!"));
    }

    //Check if Isogram
    //Prompt to guess again
    //Check if its the right number of characters
    //Prompt to guess again

    //Remove Life

    //Check if lives > 0
    //If Yes GuessAgain
    //If no show GameOver and HiddenWord
    //Prompt to play again, Press enter to play again
    //Playagain or quit
    
}

void UBullCowCatridge::InitGame()
{
    HiddenWord = TEXT("cake"); //Set the HiddenWord
    //Set Lives
}