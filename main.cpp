//
//  main.cpp
//  Yahtzee multiplayer
//
//  Created by Philip Andersson on 2018-10-18.
//  Copyright © 2018 KTC. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <array>
#include <string>
using namespace std;

int chose1, chose2, chose3, chose4, chose5, choseScore, PlayersTurn, NumberOfPlayers;
char omstart;
// slot 0 = aces | slot 1 = twos | slot 2 = threes | slot 3 = fours slot | 4 = Fives slot | 5 = Sixes
// slot 6 = Pairs | slot 7 = TwoPairs | slot 8 = 3 of a kind | slot 9 = 4 of a kind | slot 10 = full house
// slot 11 = small straight | slot 12 = large straight | slot 13 = chance | slot 14 = yahtzee
// slot 15 = upper score | slot 16 = lower score | slot 17 = grand total | slot 18 = bonus | slot 19 = lock 1 | slot 20 = lock 2 | slot 21 = lock 3
//slot 22 = lock 4 | slot 23 = lock 5 | slot 24 = lock 6 | slot 25 = lock 7 | slot 26 = lock 8 | slot 27 = lock 9
// slot 28 = lock 10 | slot 29 = lock 11 | slot 30 = lock 12 | slot 31 = lock 13 | slot 32 = lock 14 | lock 33 = lock 15
array<int, 34> ScoreP1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
array<int, 34> ScoreP2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
array<int, 34> ScoreP3 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
array<int, 34> ScoreP4 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
array<int, 34> ScoreP5 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
array<int, 34> ScoreP6 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
array<string, 6> Names = {"0", "0", "0", "0", "0", "0"};
array<array<int, 34>, 6> Players = {ScoreP1, ScoreP2, ScoreP3, ScoreP4, ScoreP5, ScoreP6};
// slot 0 = Dice 1 | slot 1 = Dice 2 | slot 2 = Dice 3 | slot 3 = Dice 4 | slot 4 = Dice 5
array<int, 5> Dices = {0, 0, 0, 0, 0};

void choises();
void scoreboard();
int dice();
void scorecheck();
void showDices();
int saveDices();

int main ()
{
    srand(time(NULL));
    cout << "How many players are you? Maximum is six." << endl;
    cin >> NumberOfPlayers;
    do
    {
        if (PlayersTurn >= NumberOfPlayers)
        {
            PlayersTurn = 0;
        }
        for (int i = 0; i < NumberOfPlayers; i++)
        {
            if (Names[i] == "0")
            {
                cout << "What are player " << i + 1 << "'s name?" << endl;
                cin >> Names[i];
            }
        }
        cout << Names[PlayersTurn] << "'s turn!" << endl;
        dice();
        showDices();
        choises();
        saveDices();
        for (int i = 0; i < 1; i++){
            cout << Names[PlayersTurn] << "'s turn!" << endl;
            showDices();
            choises();
            saveDices();
        }
        scoreboard();
        showDices();
        scorecheck();
        scoreboard();
        PlayersTurn++;
        cout << "Is the next player ready? Y/N" << endl;
        cin >> omstart;
    }while (omstart == 'Y'  || omstart == 'y');
    return 0;
}
int saveDices()
{
    srand(time(NULL));
    if (chose1 != 1)
    {
        Dices[0] = rand() % 6 + 1;
    }
    if (chose2 != 1)
    {
        Dices[1] = rand() % 6 + 1;
    }
    if (chose3 != 1)
    {
        Dices[2] = rand() % 6 + 1;
    }
    if (chose4 != 1)
    {
        Dices[3] = rand() % 6 + 1;
    }
    if (chose5 != 1)
    {
        Dices[4] = rand() % 6 + 1;
    }
    return Dices[0];
    return Dices[1];
    return Dices[2];
    return Dices[3];
    return Dices[4];
}
void showDices ()
{
    cout << "Dice one:   " << Dices[0] << endl;
    cout << "Dice two:   " << Dices[1] << endl;
    cout << "Dice three: " << Dices[2] << endl;
    cout << "Dice four:  " << Dices[3] << endl;
    cout << "Dice five:  " << Dices[4] << endl;
}
void scorecheck ()
{
    sort(Dices.begin(), Dices.end());
    cout << "What score do you want to put it in?" << endl;
    cin >> choseScore;
    if (choseScore == 1 && Players[PlayersTurn][19] != 1)
    {
        for (int i = 0; i < 5; i++)
        {
            if (Dices[i] == 1)
            {
               Players[PlayersTurn][0] += 1;
            }
        }
        Players[PlayersTurn][19] = 1;
    }
    else if (choseScore == 2 && Players[PlayersTurn][20] != 2)
    {
        for (int i = 0; i < 5; i++)
        {
            if (Dices[i] == 2)
            {
                Players[PlayersTurn][1] += 2;
            }
        }
        Players[PlayersTurn][20] = 2;
    }
    else if (choseScore == 3 && Players[PlayersTurn][21] != 3)
    {
        for (int i = 0; i < 5; i++)
        {
            if (Dices[i] == 3)
            {
                Players[PlayersTurn][2] += 3;
            }
        }
        Players[PlayersTurn][21] = 3;
    }
    else if (choseScore == 4 && Players[PlayersTurn][22] != 4)
    {
        for (int i = 0; i < 5; i++)
        {
            if (Dices[i] == 4)
            {
                Players[PlayersTurn][3] += 4;
            }
        }
        Players[PlayersTurn][22] = 4;
    }
    else if (choseScore == 5 && Players[PlayersTurn][23] != 5)
    {
        for (int i = 0; i < 5; i++)
        {
            if (Dices[i] == 5)
            {
                Players[PlayersTurn][4] += 5;
            }
        }
        Players[PlayersTurn][23] = 5;
    }
    else if (choseScore == 6 && Players[PlayersTurn][24] != 6)
    {
        for (int i = 0; i < 5; i++)
        {
            if (Dices[i] == 6)
            {
                Players[PlayersTurn][5] += 6;
            }
        }
        Players[PlayersTurn][24] = 6;
    }
    else if (choseScore == 7 && Players[PlayersTurn][25] != 7)
    {
        for (int i = 0; i < Dices.size(); i++)
        {
            if (Dices[i] == Dices[i-1])
            {
                Players[PlayersTurn][6] = Dices[i] * 2;
            }
        }
        Players[PlayersTurn][25] = 7;
    }
    else if (choseScore == 8 && Players[PlayersTurn][26] != 8)
    {
        for (int i = 0; i < Dices.size(); i++)
        {
           if (Dices[i] == Dices[i-1] && Dices[i-2] == Dices[i-3])
           {
             Players[PlayersTurn][7] = Dices[i] + Dices[i-1] + Dices[i-2] + Dices [i-3];
           }
           else if (Dices[i] == Dices[i-1] && Dices[i-3] == Dices[i-4])
           {
              Players[PlayersTurn][7] = Dices[i] + Dices[i-1] + Dices[i-3] + Dices [i-4];
           }
        }
        Players[PlayersTurn][26] = 8;
    }
    else if (choseScore == 9 && Players[PlayersTurn][27] != 9)
    {
        for (int i = 0; i < Dices.size(); i++)
        {
            if (Dices[i] == Dices[i-1] && Dices[i] == Dices[i-2])
            {
                Players[PlayersTurn][8] = Dices[i] * 3;
            }
        }
        Players[PlayersTurn][27] = 9;
    }
    else if (choseScore == 10 && Players[PlayersTurn][28] != 10)
    {
        for (int i = 0; i < Dices.size(); i++)
        {
            if (Dices[i] == Dices[i-1] && Dices[i] == Dices[i-2] && Dices[i] == Dices[i-3])
            {
                Players[PlayersTurn][9] = Dices[i] * 4;
            }
        }
        Players[PlayersTurn][28] = 10;
    }
    else if (choseScore == 11 && Players[PlayersTurn][29] != 11)
    {
        if (Dices[0] == Dices[1] && Dices[2] == Dices[3] && Dices[3] == Dices[4])
        {
            Players[PlayersTurn][10] = Dices[0] * 2 + Dices[2] * 3;
        }
        else if (Dices[0] == Dices[1] && Dices[1] == Dices[2] && Dices[3] == Dices[4])
        {
           Players[PlayersTurn][10] = Dices[0] * 3 + Dices[2] * 2;
        }
        Players[PlayersTurn][29] = 11;
    }
    else if (choseScore == 12 && Players[PlayersTurn][30] != 12)
    {
        if (Dices[0] != Dices[1] != Dices[2] != Dices[3] != Dices[4] && Dices[0] + Dices[1] + Dices[2] + Dices[3] + Dices[4] == 15 && Dices[0] != 6 && Dices[1] != 6 && Dices[2] != 6 && Dices[3] != 6 && Dices[4] != 6)
        {
            Players[PlayersTurn][11] += 15;
        }
        Players[PlayersTurn][30] = 12;
    }
    else if (choseScore == 13 && Players[PlayersTurn][31] != 13)
    {
        if (Dices[0] != Dices[1] != Dices[2] != Dices[3] != Dices[4] && Dices[0] + Dices[1] + Dices[2] + Dices[3] + Dices[4] == 20 && Dices[0] != 1 && Dices[1] != 1 && Dices[2] != 1 && Dices[3] != 1 && Dices[4] != 1)
        {
            Players[PlayersTurn][12] += 20;
        }
        Players[PlayersTurn][31] = 13;
    }
    else if (choseScore == 14 && Players[PlayersTurn][32] != 14)
    {
        Players[PlayersTurn][13] = Dices[0] + Dices[1] + Dices[2] + Dices[3] + Dices[4];
        Players[PlayersTurn][32] = 14;
    }
    else if (choseScore == 15 && Players[PlayersTurn][33] != 15)
    {
        if (Dices[0] == Dices[1] && Dices[1] == Dices[2] && Dices[2] == Dices[3] && Dices[3] == Dices[4])
        {
            Players[PlayersTurn][14] += 50;
        }
        Players[PlayersTurn][33] = 15;
    }
    Players[PlayersTurn][15] = Players[PlayersTurn][0] + Players[PlayersTurn][1] + Players[PlayersTurn][2] + Players[PlayersTurn][3] + Players[PlayersTurn][4] + Players[PlayersTurn][5] + Players[PlayersTurn][18];
    Players[PlayersTurn][16] = Players[PlayersTurn][6] + Players[PlayersTurn][7] + Players[PlayersTurn][8] + Players[PlayersTurn][9] + Players[PlayersTurn][10] + Players[PlayersTurn][11] + Players[PlayersTurn][12] + Players[PlayersTurn][13] + Players[PlayersTurn][14];
    if (Players[PlayersTurn][15] >= 63)
    {
        Players[PlayersTurn][18] = 25;
    }
    Players[PlayersTurn][15] = Players[PlayersTurn][0] + Players[PlayersTurn][1] + Players[PlayersTurn][2] + Players[PlayersTurn][3] + Players[PlayersTurn][4] + Players[PlayersTurn][5] + Players[PlayersTurn][18];
    Players[PlayersTurn][17] = Players[PlayersTurn][15] + Players[PlayersTurn][16];
}



int dice ()
{
    srand(time(NULL));
    Dices[0] = rand() % 6 + 1;
    Dices[1] = rand() % 6 + 1;
    Dices[2] = rand() % 6 + 1;
    Dices[3] = rand() % 6 + 1;
    Dices[4] = rand() % 6 + 1;
    return Dices[0];
    return Dices[1];
    return Dices[2];
    return Dices[3];
    return Dices[4];
}
void choises ()
{
    cout << "What dices do you want to keep? 1 is save everything else is throw." << endl;
    cout << "Dice one:" << endl;
    cin >> chose1;
    cout << "Dice two:" << endl;
    cin >> chose2;
    cout << "Dice three:" << endl;
    cin >> chose3;
    cout << "Dice four" << endl;
    cin >> chose4;
    cout << "Dice five:" << endl;
    cin >> chose5;
}
void scoreboard ()
{
    cout << "What score do you want to put it in?" << endl;
    cout << "=============================================" << endl;
    cout << "=============> Upper section <===============" << endl;
    cout << "=============================================" << endl;
    cout << "                    | " << Names[0] << " | " << Names[1] << " | "<< Names[2] << " | " << Names[3] << " | " << Names[4] << " | " << Names[5] <<" |" << endl;
    cout << "                    -------------------------" << endl;
    cout << "1.Aces:             | " << Players[0][0] << " | " << Players[1][0] << " | " << Players[2][0] << " | " << Players[3][0] << " | " << Players[4][0] << " | " << Players[5][0] << " | " << endl;
    cout << "2.Twos:             | " << Players[0][1] << " | " << Players[1][1] << " | " << Players[2][1] << " | " << Players[3][1] << " | " << Players[4][1] << " | " << Players[5][1] << " | " << endl;
    cout << "3.Threes:           | " << Players[0][2] << " | " << Players[1][2] << " | " << Players[2][2] << " | " << Players[3][2] << " | " << Players[4][2] << " | " << Players[5][2] << " | " << endl;
    cout << "4.Fours:            | " << Players[0][3] << " | " << Players[1][3] << " | " << Players[2][3] << " | " << Players[3][3] << " | " << Players[4][3] << " | " << Players[5][3] << " | " << endl;
    cout << "5.Fives:            | " << Players[0][4] << " | " << Players[1][4] << " | " << Players[2][4] << " | " << Players[3][4] << " | " << Players[4][4] << " | " << Players[5][4] << " | " << endl;
    cout << "6.Sixes:            | " << Players[0][5] << " | " << Players[1][5] << " | " << Players[2][5] << " | " << Players[3][5] << " | " << Players[4][5] << " | " << Players[5][5] << " | " << endl;
    cout << "Bonus:              | " << Players[0][18] << " | " << Players[1][18] << " | " << Players[2][18] << " | " << Players[3][18] << " | " << Players[4][18] << " | " << Players[5][18] << " | " << endl;
    cout << "Total:              | " << Players[0][15] << " | " << Players[1][15] << " | " << Players[2][15] << " | " << Players[3][15] << " | " << Players[4][15] << " | " << Players[5][15] << " | " << endl;
    cout << "=============================================" << endl;
    cout << "=============> Lower section <===============" << endl;
    cout << "=============================================" << endl;
    cout << "7.Pair:             | " << Players[0][6] << " | " << Players[1][6] << " | " << Players[2][6] << " | " << Players[3][6] << " | " << Players[4][6] << " | " << Players[5][6] << " | " << endl;
    cout << "8.Two Pairs:        | " << Players[0][7] << " | " << Players[1][7] << " | " << Players[2][7] << " | " << Players[3][7] << " | " << Players[4][7] << " | " << Players[5][7] << " | " << endl;
    cout << "9.3 of a kind:      | " << Players[0][8] << " | " << Players[1][8] << " | " << Players[2][8] << " | " << Players[3][8] << " | " << Players[4][8] << " | " << Players[5][8] << " | " << endl;
    cout << "10.4 of a kind:     | " << Players[0][9] << " | " << Players[1][9] << " | " << Players[2][9] << " | " << Players[3][9] << " | " << Players[4][9] << " | " << Players[5][9] << " | " << endl;
    cout << "11.Full house:      | " << Players[0][10] << " | " << Players[1][10] << " | " << Players[2][10] << " | " << Players[3][10] << " | " << Players[4][10] << " | " << Players[5][10] << " | " << endl;
    cout << "12.Small straight:  | " << Players[0][11] << " | " << Players[1][11] << " | " << Players[2][11] << " | " << Players[3][11] << " | " << Players[4][11] << " | " << Players[5][11] << " | " << endl;
    cout << "13.Large straight:  | " << Players[0][12] << " | " << Players[1][12] << " | " << Players[2][12] << " | " << Players[3][12] << " | " << Players[4][12] << " | " << Players[5][12] << " | " << endl;
    cout << "14.Chance:          | " << Players[0][13] << " | " << Players[1][13] << " | " << Players[2][13] << " | " << Players[3][13] << " | " << Players[4][13] << " | " << Players[5][13] << " | " << endl;
    cout << "15.Yahtzee:         | " << Players[0][14] << " | " << Players[1][14] << " | " << Players[2][14] << " | " << Players[3][14] << " | " << Players[4][14] << " | " << Players[5][14] << " | " << endl;
    cout << "Your upper score:   | " << Players[0][15] << " | " << Players[1][15] << " | " << Players[2][15] << " | " << Players[3][15] << " | " << Players[4][15] << " | " << Players[5][15] << " | " << endl;
    cout << "Your lower score:   | " << Players[0][16] << " | " << Players[1][16] << " | " << Players[2][16] << " | " << Players[3][16] << " | " << Players[4][16] << " | " << Players[5][16] << " | " << endl;
    cout << "Your total score:   | " << Players[0][17] << " | " << Players[1][17] << " | " << Players[2][17] << " | " << Players[3][17] << " | " << Players[4][17] << " | " << Players[5][17] << " | " << endl;
}

