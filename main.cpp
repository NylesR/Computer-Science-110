    //
    //  main.cpp
    //  Final Project
    //
    //  Created by Nyles Randall on 12/3/19.
    //  Copyright © 2019 Nyles Randall. All rights reserved.
    //

    #include <iostream>
    #include <ctime>
    using namespace std;

    // RPS is short for Rock Paper Scissors!

    // Global Variable Initilization

    int playerRPSChoice = 0; // The variable that holds the players choice in RPS
    int* playerPtrChoice = &playerRPSChoice;

    int cpuRPSChoice = 0; // The variable that holds the computers choice in RPS
    int* cpuPtrRPSChoice = &cpuRPSChoice;

    bool validChoice = false; // Decides whether or not the player's choice in RPS is valid
    bool* ptrPChoice = &validChoice;

    const unsigned short int roomSize = 5; // Room size for the game

    int Room[roomSize]; // Array for the rooms

    int correctDoor; // Variable that holds the correct door
    int* ptrCDoor = new int;

    int playerDChoice; // The variable that holds the player's choice for the door.
    int* ptrPlayerDChoice = &playerDChoice;
    
    unsigned short int playerpts = 0;

    bool statusRPS = false; // Checks to see if the game is rock paper scissors

    bool statusCF = false; // Checks to see if the game is coin flip

    int plyrCoinFlip; // The player's input for coinflip
    int* ptrPlyCoin = &plyrCoinFlip;

    int cpuCoinFlip; // The computers input for coin flip
    int* ptrCpuCoin = &cpuCoinFlip;
    
    int playerScore = 0; // The player's score
    int* ptrPlayerScore = &playerScore;

    int lifepool = 1; // The amount of lives the player has
    int* ptrLife = &lifepool;

    // ---------------------------

    void checkPlayerRPS(); /* Function that checks to make sure the player chose a valid option.
                            Will repeat the function until the user picks a valid option. */

    void pickRPS(); /* Function that asks the player to pick Rock Paper or Scissors once
                    prompted*/

    int compRPS(); /* Function gives the computer's answer to Rock Paper Scissor's games via a random number
                    generator through seeded random responses */

    void chooseRoomNumbers(); /* Random number generator that chooses a random number for each designated room for
                               each door*/

    void chooseCorrectNumber(); // Chooses a correct door number

    void determineGame(); // Determines whether or not the game will be RPS or Coin Toss

    void askPlayer(); // Asks the player which door he or she would like to open

    void whoWonRPS(); // Decides the winner of the RPS round.
    
    void doorRPS (); // Occurs whenever a player opens a Rock Paper Scissors door.

    void coinFlipGame(); // Runs the coin flip portion of the game

    void cpuCoinInput(); // Gets the computer's input for the coinflip

    void playerCoinInput(); // Gets the player's input for the coinflip

    void whoWonCF(); // Decides who won the coinflip round using a RNG.

    // --------------------------

    int main(){
        
        chooseRoomNumbers();
        
        askPlayer();
        
        chooseCorrectNumber();
        
        determineGame();
        
        if (lifepool == 0){
            
            cout << "Your final score was: " << playerScore << "." << endl;
            
        }
        
        return 0;
    }


// ------------------------------------------------------

   void askPlayer(){
       
       cout << "Would you like to choose door 1, 2, 3, 4, or 5?" << endl;
       
       cin >> playerDChoice;
       
       if (playerDChoice > 5 || playerDChoice < 1){
           cout << "Please choose a valid door option!" << endl << endl;
               askPlayer();
       }
       else{
           
       cout << "You chose door " << playerDChoice << endl;
           
       }
       return;
   }

// ------------------------------------------------------

   void determineGame(){

       statusRPS = false;
       statusCF = false;
       
       
       if (Room[playerDChoice - 1] % 2 == 0){
           
           cout << "This is a Rock Paper Scissors Door!" << endl;
           statusRPS = true;
           statusCF = false;
           if(statusRPS == true){
               doorRPS();
           }
           
       }
       
       else{
           cout << "This is a Coin Flip Door!" << endl;
           statusCF = true;
           statusRPS = false;
           if(statusCF == true){
               coinFlipGame();
           }
       }
       
       
   }

// ------------------------------------------------------

    void chooseCorrectNumber(){
        
        srand(static_cast<unsigned int>(time(NULL)));
        
        *ptrCDoor = rand() % 5;
            
            ++*ptrCDoor; // Adds one to the correct door due to one-off errors.
            
        if (*ptrPlayerDChoice == *ptrCDoor){
            
            cout << "You chose the correct door! You advance to the next room." << endl;
            ++*ptrPlayerScore;
            cout << "You gain a point." << endl;
            cout << "Your total score is now " << *ptrPlayerScore << "." << endl;
            
            main();
            exit(-1);
        }
        return;
    }

// ------------------------------------------------------


void chooseRoomNumbers(){
    
    srand(static_cast<unsigned short int>(time(NULL)));
    
    for (int i = 0; i < roomSize; i++){
    
        Room[i] = rand() % 99;
        
        cout << "[" << Room[i] << "] ";
    
    }
    
    cout << endl;
        
        for (int i = 0; i < 5; i++){
        
            cout << " D" << (i + 1) << "  ";
        
        }
    
    cout << endl;
    
    return;
}

// ------------------------------------------------------

    void pickRPS(){
        
        *ptrPChoice = false;
        
       cout << "Choose Rock, Paper, or Scissors." << endl;
        
        cout << "1. Rock" << endl << "2. Paper" << endl << "3. Scissors" << endl;
        
        cin >> *playerPtrChoice;

    // Tells the player they chose Rock
        
        if (*playerPtrChoice == 1){
            cout << "You chose Rock." << endl;
            *ptrPChoice = true; // Check to see if they player's choice was valid
            
        }
    // Tells the player they chose Paper.
        
        else if (*playerPtrChoice == 2){
             cout << "You chose Paper." << endl;
            *ptrPChoice = true; // Check to see if they player's choice was valid
            
        }
    // Tells the player they chose Scissors.
        
        else if (playerRPSChoice == 3){
             cout << "You chose Scissors." << endl;
            *ptrPChoice = true; // Check to see if they player's choice was valid
            
        }
        
    // Default option if player does not choose Rock Paper or Scissors.
        else {
            cout << "Please choose a valid option!" << endl;
            *ptrPChoice = false; // Check to see if they player's choice was invalid
        }
        
        return;
        
    }

// ------------------------------------------------------

    void checkPlayerRPS(){
        
        *ptrPChoice = false; // resets the players choice to false after every round to avoid skipping pickRPS
        
        while (*ptrPChoice == false) {
            
            pickRPS();
            
        }
        
    }

// ------------------------------------------------------


    int compRPS(){
        
        srand(static_cast<unsigned short int>(time(NULL)));
        
        *cpuPtrRPSChoice = rand() % 3;
        
        if (cpuRPSChoice == 0){
            
            cout << "The computer chose Rock!" << endl << endl;
            
        }
        else if (cpuRPSChoice == 1){
            
            cout << "The computer chose Paper!" << endl << endl;
            
        }
        
        else if (cpuRPSChoice == 2){
            
            cout << "The computer chose Scissors!" << endl << endl;
        }
        
        return 0;
    }

// ------------------------------------------------------

    void whoWonRPS(){
    
        bool tieGame = false;
        
        enum plyrRPS {BLANK, pROCK, pPAPER, pSCISSORS};
        enum cpuRPS {cROCK, cPAPER, cSCISSORS};
        
        if (*playerPtrChoice == *cpuPtrRPSChoice + 1){ // +1 to make the cpu choice even to the players since the cpu starts at 0
            
            cout << "Tie game. Choose again" << endl;
            tieGame = true;
            if(tieGame == true){ // Occurs only when a tie game of Rock Paper Scissors occurs.. Requires the player to play again.
                *ptrPChoice = false;
                doorRPS ();
                return;
            }
        }
        else if (*playerPtrChoice == pROCK && *cpuPtrRPSChoice == cPAPER){ // Rock < Paper
            
            cout << "Computer wins, game over.." << endl;
            --*ptrLife;
            return;
        }
        
        else if(*playerPtrChoice == pROCK && *cpuPtrRPSChoice == cSCISSORS){ // Rock > Scissors
            
            cout << "You win! You advance to the next room" << endl << "You gained a point." << endl;
            ++*ptrPlayerScore;
            cout << "Your total score is now " << *ptrPlayerScore << "." << endl;
            
            main();
        }
        
        else if(*playerPtrChoice == pPAPER && *cpuPtrRPSChoice == cROCK){ // Paper > Rock
            
            cout << "You win! You advance to the next room" << endl << "You gained a point." << endl;
            ++*ptrPlayerScore;
            cout << "Your total score is now " << *ptrPlayerScore << "." << endl;
            
            main();
        }
        
        else if (*playerPtrChoice == pPAPER && *cpuPtrRPSChoice == cSCISSORS){ // Paper < Scissors
            
            cout << "Computer wins, game over.." << endl;
            --*ptrLife;
        }
        
        else if(*playerPtrChoice == pSCISSORS && *cpuPtrRPSChoice == cROCK){ // Scissors < Rock
                   
            cout << "Computer wins, game over.." << endl;
            --*ptrLife;
        }
        
        else if(*playerPtrChoice == pSCISSORS && *cpuPtrRPSChoice == cPAPER){ // Scissors > Paper
            
            cout << "You win! You advance to the next room" << endl << "You gained a point." << endl;
            ++*ptrPlayerScore;
            cout << "Your total score is now " << *ptrPlayerScore << "." << endl;
            
            main();
        }
        
        else {
            
            cout << "Error!" << endl;
            
        }
    
    }

// ------------------------------------------------------

    void doorRPS (){
        
        checkPlayerRPS();
        compRPS();
        whoWonRPS();
    
    }

// COIN PORTION OF THE GAME // ------------------------------------------------------

    void coinFlipGame(){
        
        playerCoinInput();
        
        while (*ptrPlyCoin > 2 || *ptrPlyCoin < 1){
            
            cout << "Invalid option.." << endl;
            playerCoinInput();
            
        }
        
        if(*ptrPlyCoin == 1){
            
            cout << "You chose Heads" << endl;
        }
        else if(*ptrPlyCoin == 2){
            
            cout << "You chose Tails" << endl;
        }
        else{
            
            cout << "System Error.." << endl;
            
        }

        
        cpuCoinInput();
        
        whoWonCF();
    
    }

    void cpuCoinInput(){
        enum Coins {NOTHING, HEADS, TAILS};
        
        if(plyrCoinFlip == HEADS){
            
            *ptrCpuCoin = TAILS;
            cout << "The computer choses Tails" << endl; // If the player chooses Heads the computer chooses Tails by default
            
        }
        else if(plyrCoinFlip == TAILS){
            
            *ptrCpuCoin = HEADS;
            cout << "The computer choses Heads" << endl; // If the player chooses Tails the computer chooses Heads by default
        }
        else{
            
            cout << "Error Game Crashed..";
            
        }
    }

    void playerCoinInput(){
        
        cout << "Do you want to choose Heads or Tails? " << endl << "1. Heads " << endl << "2. Tails" << endl;
           
        cin >> *ptrPlyCoin;
    
    }



    void whoWonCF(){
    
        int theCoin;
        
        enum Coins {HEADS, TAILS};
        
        srand(static_cast<unsigned int>(time(NULL)));
        
        theCoin = rand() %2;
        
        if(theCoin == HEADS){
            
            cout << "The coin landed on..." << endl;
            
            cout << "Heads!" << endl;
            
            if (*ptrPlyCoin == 1){
                
                cout << "You won the coin flip round! You advance to the next room." << endl;
                ++*ptrPlayerScore;
                cout << "You gain a point." << endl;
                cout << "Your total score is now " << *ptrPlayerScore << "." << endl;
                
                main();
                return;
                
            }
            else if (*ptrCpuCoin == 1){
                
                cout << "You lost the coin flip round..." << endl << "Game Over.." << endl;
                --*ptrLife;
            }
            
        }
        
        else if(theCoin == TAILS){
                   
            cout << "The coin landed on..." << endl;
                   
            cout << "Tails!" << endl;
            
            if (*ptrPlyCoin == 2){
                               
                    cout << "You won the coin flip round! You advance to the next room." << endl;
                    ++*ptrPlayerScore;
                    cout << "You gain a point." << endl;
                    cout << "Your total score is now " << *ptrPlayerScore << "." << endl;
                               
                               main();
                return;
                               
                }
            else if (*ptrCpuCoin == 2){
                               
                cout << "You lost the coin flip round..." << endl << "Game Over.." << endl;
                --*ptrLife;
                }
            }
        else{
            
            cout << "Error occurred, Game over..." << endl;
            return;
        }
        
        
    }

