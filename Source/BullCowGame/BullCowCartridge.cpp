// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    GetValidWords(WordList);
    SetupGame();

    PrintLine(TEXT("The number of possible words is %i"), WordList.Num());
    PrintLine(TEXT("The number of valid words is: %i."), GetValidWords(WordList).Num());
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
        ProcessGuess(Input);
     
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
    Lives = HiddenWord.Len();//Set Lives
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess and \npress enter to continue..."));

    const TCHAR HW[] = TEXT("plums");
    PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]);
    PrintLine(TEXT("The 4th character of HW is HW: %c"), HW[3]);

    IsIsogram(HiddenWord);
  
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
 
    PrintLine(TEXT("\nPress enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{

       if  (Guess == HiddenWord) //Move outside this function.
        {
            PrintLine(TEXT("You have won!"));
            EndGame();
            return;
        }

        if (!IsIsogram(Guess))
        {
            PrintLine(TEXT("No repeating letters, guess again"));
            return;
        }

          if (Guess.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
                    PrintLine(TEXT("The hidden word is %i letter long."), HiddenWord.Len());
                    return;
                }

        //Removes Life
        PrintLine(TEXT("Lost a life!"));
        --Lives;
        
            if (Lives <= 0)
            {
                    ClearScreen();
                    PrintLine(TEXT("You have no lives left!"));
                    PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
              
                    EndGame();
                    return;
            }
             
             //Show the player Bulls and Cows
             PrintLine(TEXT("Guess again, you have %i lives left"), Lives);

}


bool UBullCowCartridge::IsIsogram(FString Word) const
{

    for (int32 Index = 0; Index < Word.Len(); Index++ )
    {
        for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
        }

    }

TArray<FString> UBullCowCartridge::GetValidWords(TArray<FString> WordList) const
{
     TArray<FString> ValidWords;

    for (FString Word : WordList)
    {
        if (WordList[Index].Len() >= 4 && WordList[Index].Len() <=8 && IsIsogram(WordList[Index]))
            {
                
                ValidWords.Emplace(WordList[Index]);
            
              
            }
    }

    return ValidWords;
}


    return true;
}