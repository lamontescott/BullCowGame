// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord);//Debug Line

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

    //if the game is over then do ClearScreen() and SetGame() the game

    if(bGameOver)
        {
            ClearScreen();
            SetupGame();
        }
    else //Checking PlayerGuess
    {
        if  (Input == HiddenWord) //Move outside this function.
        {
            PrintLine(TEXT("You have won!"));
            EndGame();
        }
        else 
        {
            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The Hidden Word is %i character long, try again! "), HiddenWord.Len()); //Magic Number
                EndGame();
            }

            PrintLine(TEXT("You have Lost!"));
        }
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

void UBullCowCartridge::SetupGame()
{

    PrintLine(TEXT("Welcome to Bull Cows!"));

    HiddenWord = TEXT("cakes"); //Set the HiddenWord
    Lives = 4;//Set Lives
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess. \nPress enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}