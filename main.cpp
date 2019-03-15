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

//LengthOfName1, LengthOfScore1P1, LengthOfScore2P1, LengthOfScore3P1, LengthOfScore4P1,LengthOfScore5P1, LengthOfScore6P1, LengthOfScore7P1, LengthOfScore8P1, LengthOfScore9P1, LengthOfScore10P1, LengthOfScore11P1, LengthOfScore12P1, LengthOfScore13P1, LengthOfScore14P1, LengthOfScore15P1;
array<int, 21> LengthOfP1= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0};
array<int, 21> LengthOfP2= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
array<int, 21> LengthOfP3= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
array<int, 21> LengthOfP4= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
array<int, 21> LengthOfP5= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
array<int, 21> LengthOfP6= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int choseScore, PlayersTurn, NumberOfPlayers;
char chose1, chose2, chose3, chose4, chose5;
char omstart;
// slot 0 = aces | slot 1 = twos | slot 2 = threes | slot 3 = fours slot | 4 = Fives slot | 5 = Sixes
// slot 6 = Pairs | slot 7 = TwoPairs | slot 8 = 3 of a kind | slot 9 = 4 of a kind | slot 10 = full house
// slot 11 = small straight | slot 12 = large straight | slot 13 = chance | slot 14 = yahtzee
// slot 15 = upper score | slot 16 = lower score | slot 17 = grand total | slot 18 = bonus | slot 19 = lock 1 | slot 20 = lock 2 | slot 21 = lock 3
//slot 22 = lock 4 | slot 23 = lock 5 | slot 24 = lock 6 | slot 25 = lock 7 | slot 26 = lock 8 | slot 27 = lock 9
// slot 28 = lock 10 | slot 29 = lock 11 | slot 30 = lock 12 | slot 31 = lock 13 | slot 32 = lock 14 | slot 33 = lock 15
array<int, 34> ScoreP1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
array<int, 34> ScoreP2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
array<int, 34> ScoreP3 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
array<int, 34> ScoreP4 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
array<int, 34> ScoreP5 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
array<int, 34> ScoreP6 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0};
array<string, 6> Names = {"", "", "", "", "", ""};
array<array<int, 34>, 6> Players = {ScoreP1, ScoreP2, ScoreP3, ScoreP4, ScoreP5, ScoreP6};
// slot 0 = Dice 1 | slot 1 = Dice 2 | slot 2 = Dice 3 | slot 3 = Dice 4 | slot 4 = Dice 5
array<int, 5> Dices = {0, 0, 0, 0, 0};

void choises();
void scoreboard();
int dice();
void scorecheck();
void showDices();
void saveDices();

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
            if (Names[i] == "")
            {
                cout << "What are player " << i + 1 << "'s name? (No spaces)" << endl;
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
void saveDices()
{
    srand(time(NULL));
    if (chose1 != 'Y' && chose1 != 'y')
    {
        Dices[0] = rand() % 6 + 1;
    }
    if (chose2 != 'Y' && chose2 != 'y')
    {
        Dices[1] = rand() % 6 + 1;
    }
    if (chose3 != 'Y' && chose3 != 'y')
    {
        Dices[2] = rand() % 6 + 1;
    }
    if (chose4 != 'Y' && chose4 != 'y')
    {
        Dices[3] = rand() % 6 + 1;
    }
    if (chose5 != 'Y' && chose5 != 'y')
    {
        Dices[4] = rand() % 6 + 1;
    }
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
        if (choseScore == Players[PlayersTurn][19] || choseScore == Players[PlayersTurn][21] || choseScore == Players[PlayersTurn][22] || choseScore == Players[PlayersTurn][23] || choseScore == Players[PlayersTurn][24] || choseScore == Players[PlayersTurn][25] || choseScore == Players[PlayersTurn][26] || choseScore == Players[PlayersTurn][27] || choseScore == Players[PlayersTurn][28] || choseScore == Players[PlayersTurn][29] || choseScore == Players[PlayersTurn][30] || choseScore == Players[PlayersTurn][31] || choseScore == Players[PlayersTurn][32] || choseScore == Players[PlayersTurn][33] || choseScore == Players[PlayersTurn][20])
        {
            scoreboard();
            showDices();
            scorecheck();
            scoreboard();
        }
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
        else if (Dices[0] == Dices[1] && Dices[2] == Dices[3] && Dices[3] == Dices[4])
        {
           Players[PlayersTurn][10] = Dices[0] * 2 + Dices[2] * 3;
        }
        else if (Dices[0] == Dices[2] && Dices[1] == Dices[3] && Dices[3] == Dices[4])
        {
            Players[PlayersTurn][10] = Dices[0] * 2 + Dices[1] * 3;
        }
        else if (Dices[0] == Dices[3] && Dices[1] == Dices[2] && Dices[2] == Dices[4])
        {
            Players[PlayersTurn][10] = Dices[0] * 2 + Dices[1] * 3;
        }
        else if (Dices[0] == Dices[4] && Dices[1] == Dices[2] && Dices[3] == Dices[2])
        {
            Players[PlayersTurn][10] = Dices[0] * 2 + Dices[1] * 3;
        }
        else if (Dices[1] == Dices[2] && Dices[0] == Dices[3] && Dices[3] == Dices[4])
        {
            Players[PlayersTurn][10] = Dices[1] * 2 + Dices[0] * 3;
        }
        else if (Dices[1] == Dices[3] && Dices[0] == Dices[2] && Dices[2] == Dices[4])
        {
            Players[PlayersTurn][10] = Dices[1] * 2 + Dices[0] * 3;
        }
        else if (Dices[1] == Dices[4] && Dices[0] == Dices[2] && Dices[2] == Dices[3])
        {
            Players[PlayersTurn][10] = Dices[1] * 2 + Dices[0] * 3;
        }
        else if (Dices[2] == Dices[3] && Dices[0] == Dices[1] && Dices[1] == Dices[4])
        {
            Players[PlayersTurn][10] = Dices[2] * 2 + Dices[0] * 3;
        }
        else if (Dices[2] == Dices[4] && Dices[0] == Dices[1] && Dices[1] == Dices[3])
        {
            Players[PlayersTurn][10] = Dices[2] * 2 + Dices[0] * 3;
        }
        else if (Dices[3] == Dices[4] && Dices[0] == Dices[1] && Dices[1] == Dices[2])
        {
            Players[PlayersTurn][10] = Dices[3] * 2 + Dices[0] * 2;
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
    cout << "Do you want to save Dice one? (Y / N)" << endl;
    cin >> chose1;
    cout << "Do you want to save Dice two? (Y / N)" << endl;
    cin >> chose2;
    cout << "Do you want to save Dice three? (Y / N)" << endl;
    cin >> chose3;
    cout << "Do you want to save Dice four? (Y / N)" << endl;
    cin >> chose4;
    cout << "Do you want to save Dice five? (Y / N)" << endl;
    cin >> chose5;
}
void scoreboard ()
{
    LengthOfP1[19] = Names[0].length();
    LengthOfP2[19] = Names[1].length();
    LengthOfP3[19] = Names[2].length();
    LengthOfP4[19] = Names[3].length();
    LengthOfP5[19] = Names[4].length();
    LengthOfP6[19] = Names[5].length();
    
    for (int i = 0; i < 18; i++) {
        LengthOfP1[i] = to_string(Players[0][i]).length();
        LengthOfP2[i] = to_string(Players[1][i]).length();
        LengthOfP3[i] = to_string(Players[2][i]).length();
        LengthOfP4[i] = to_string(Players[3][i]).length();
        LengthOfP5[i] = to_string(Players[4][i]).length();
        LengthOfP6[i] = to_string(Players[5][i]).length();
    }
    
    if(LengthOfP1[19] % 2 > 0)
    {
        LengthOfP1[20] = 1;
    }
    if(LengthOfP2[19] % 2 > 0)
    {
        LengthOfP2[20] = 1;
    }
    if(LengthOfP3[19] % 2 > 0)
    {
        LengthOfP3[20] = 1;
    }
    if(LengthOfP4[19] % 2 > 0)
    {
        LengthOfP4[20] = 1;
    }
    if(LengthOfP5[19] % 2 > 0)
    {
        LengthOfP5[20] = 1;
    }
    if(LengthOfP6[19] % 2 > 0)
    {
        LengthOfP6[20] = 1;
    }
    
    cout << "What score do you want to put it in?" << endl;
    cout <<  string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19])/2, '=') << "========================================" << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19])/2, '=') << endl;
    cout << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19])/2, '=') << "===========> Upper section <============" << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19])/2, '=') << endl;
    cout << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19])/2, '=') << "========================================"  << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19])/2, '=') << endl;
    
    cout << "                    | " << Names[0] << " | " << Names[1] << " | "<< Names[2] << " | " << Names[3] << " | " << Names[4] << " | " << Names[5] <<" |" << endl;
    cout << "                    -------------------" << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19]), '-') << endl;
    
    cout << "1.Aces:             | " << string((LengthOfP1[19] - (LengthOfP1[0]/2))/2, ' ') << Players[0][0] << string(((LengthOfP1[19] - (LengthOfP1[0]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[0]/2))/2, ' ') << Players[1][0] << string(((LengthOfP2[19] - (LengthOfP2[0]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[0]/2))/2, ' ') << Players[2][0] << string(((LengthOfP3[19] - (LengthOfP3[0]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[0]/2))/2, ' ') << Players[3][0] << string(((LengthOfP4[19] - (LengthOfP4[0]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[0]/2))/2, ' ') << Players[4][0] << string(((LengthOfP5[19] - (LengthOfP5[0]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[0]/2))/2, ' ') << Players[5][0] << string(((LengthOfP6[19] - (LengthOfP6[0]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "2.Twos:             | " << string((LengthOfP1[19] - (LengthOfP1[1]/2))/2, ' ') << Players[0][1] << string(((LengthOfP1[19] - (LengthOfP1[1]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[1]/2))/2, ' ') << Players[1][1] << string(((LengthOfP2[19] - (LengthOfP2[1]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[1]/2))/2, ' ') << Players[2][1] << string(((LengthOfP3[19] - (LengthOfP3[1]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[1]/2))/2, ' ') << Players[3][1] << string(((LengthOfP4[19] - (LengthOfP4[1]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[1]/2))/2, ' ') << Players[4][1] << string(((LengthOfP5[19] - (LengthOfP5[1]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[1]/2))/2, ' ') << Players[5][1] << string(((LengthOfP6[19] - (LengthOfP6[1]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "3.Threes:           | " << string((LengthOfP1[19] - (LengthOfP1[2]/2))/2, ' ') << Players[0][2] << string(((LengthOfP1[19] - (LengthOfP1[2]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[2]/2))/2, ' ') << Players[1][2] << string(((LengthOfP2[19] - (LengthOfP2[2]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[2]/2))/2, ' ') << Players[2][2] << string(((LengthOfP3[19] - (LengthOfP3[2]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[2]/2))/2, ' ') << Players[3][2] << string(((LengthOfP4[19] - (LengthOfP4[2]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[2]/2))/2, ' ') << Players[4][2] << string(((LengthOfP5[19] - (LengthOfP5[2]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[2]/2))/2, ' ') << Players[5][2] << string(((LengthOfP6[19] - (LengthOfP6[2]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "4.Fours:            | " << string((LengthOfP1[19] - (LengthOfP1[3]/2))/2, ' ') << Players[0][3] << string(((LengthOfP1[19] - (LengthOfP1[3]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[3]/2))/2, ' ') << Players[1][3] << string(((LengthOfP2[19] - (LengthOfP2[3]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[3]/2))/2, ' ') << Players[2][3] << string(((LengthOfP3[19] - (LengthOfP3[3]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[3]/2))/2, ' ') << Players[3][3] << string(((LengthOfP4[19] - (LengthOfP4[3]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[3]/2))/2, ' ') << Players[4][3] << string(((LengthOfP5[19] - (LengthOfP5[3]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[3]/2))/2, ' ') << Players[5][3] << string(((LengthOfP6[19] - (LengthOfP6[3]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "5.Fives:            | " << string((LengthOfP1[19] - (LengthOfP1[4]/2))/2, ' ') << Players[0][4] << string(((LengthOfP1[19] - (LengthOfP1[4]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[4]/2))/2, ' ') << Players[1][4] << string(((LengthOfP2[19] - (LengthOfP2[4]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[4]/2))/2, ' ') << Players[2][4] << string(((LengthOfP3[19] - (LengthOfP3[4]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[4]/2))/2, ' ') << Players[3][4] << string(((LengthOfP4[19] - (LengthOfP4[4]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[4]/2))/2, ' ') << Players[4][4] << string(((LengthOfP5[19] - (LengthOfP5[4]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[4]/2))/2, ' ') << Players[5][4] << string(((LengthOfP6[19] - (LengthOfP6[4]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "6.Sixes:            | " << string((LengthOfP1[19] - (LengthOfP1[5]/2))/2, ' ') << Players[0][5] << string(((LengthOfP1[19] - (LengthOfP1[5]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[5]/2))/2, ' ') << Players[1][5] << string(((LengthOfP2[19] - (LengthOfP2[5]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[5]/2))/2, ' ') << Players[2][5] << string(((LengthOfP3[19] - (LengthOfP3[5]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[5]/2))/2, ' ') << Players[3][5] << string(((LengthOfP4[19] - (LengthOfP4[5]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[5]/2))/2, ' ') << Players[4][5] << string(((LengthOfP5[19] - (LengthOfP5[5]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[5]/2))/2, ' ') << Players[5][5] << string(((LengthOfP6[19] - (LengthOfP6[5]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "Bonus:              | " << string((LengthOfP1[19] - (LengthOfP1[18]/2))/2, ' ') << Players[0][18] << string(((LengthOfP1[19] - (LengthOfP1[18]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[18]/2))/2, ' ') << Players[1][18] << string(((LengthOfP2[19] - (LengthOfP2[18]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[18]/2))/2, ' ') << Players[2][18] << string(((LengthOfP3[19] - (LengthOfP3[18]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[18]/2))/2, ' ') << Players[3][18] << string(((LengthOfP4[19] - (LengthOfP4[18]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[18]/2))/2, ' ') << Players[4][18] << string(((LengthOfP5[19] - (LengthOfP5[18]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[18]/2))/2, ' ') << Players[5][18] << string(((LengthOfP6[19] - (LengthOfP6[18]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "Total:              | " << string((LengthOfP1[19] - (LengthOfP1[15]/2))/2, ' ') << Players[0][15] << string(((LengthOfP1[19] - (LengthOfP1[15]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[15]/2))/2, ' ') << Players[1][15] << string(((LengthOfP2[19] - (LengthOfP2[15]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[15]/2))/2, ' ') << Players[2][15] << string(((LengthOfP3[19] - (LengthOfP3[15]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[15]/2))/2, ' ') << Players[3][15] << string(((LengthOfP4[19] - (LengthOfP4[15]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[15]/2))/2, ' ') << Players[4][15] << string(((LengthOfP5[19] - (LengthOfP5[15]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[15]/2))/2, ' ') << Players[5][15] << string(((LengthOfP6[19] - (LengthOfP6[15]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19])/2, '=') << "========================================" << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19])/2, '=') << endl;
    cout << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19])/2, '=') << "===========> Lower section <============" << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19])/2, '=') << endl;
    cout << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19])/2, '=') << "========================================" << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19])/2, '=') << endl;
    
    cout << "7.Pair:             | " << string((LengthOfP1[19] - (LengthOfP1[6]/2))/2, ' ') << Players[0][6] << string(((LengthOfP1[19] - (LengthOfP1[6]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[6]/2))/2, ' ') << Players[1][6] << string(((LengthOfP2[19] - (LengthOfP2[6]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[6]/2))/2, ' ') << Players[2][6] << string(((LengthOfP3[19] - (LengthOfP3[6]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[6]/2))/2, ' ') << Players[3][6] << string(((LengthOfP4[19] - (LengthOfP4[6]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[6]/2))/2, ' ') << Players[4][6] << string(((LengthOfP5[19] - (LengthOfP5[6]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[6]/2))/2, ' ') << Players[5][6] << string(((LengthOfP6[19] - (LengthOfP6[6]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "8.Two Pairs:        | " << string((LengthOfP1[19] - (LengthOfP1[7]/2))/2, ' ') << Players[0][7] << string(((LengthOfP1[19] - (LengthOfP1[7]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[7]/2))/2, ' ') << Players[1][7] << string(((LengthOfP2[19] - (LengthOfP2[7]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[7]/2))/2, ' ') << Players[2][7] << string(((LengthOfP3[19] - (LengthOfP3[7]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[7]/2))/2, ' ') << Players[3][7] << string(((LengthOfP4[19] - (LengthOfP4[7]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[7]/2))/2, ' ') << Players[4][7] << string(((LengthOfP5[19] - (LengthOfP5[7]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[7]/2))/2, ' ') << Players[5][7] << string(((LengthOfP6[19] - (LengthOfP6[7]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "9.3 of a kind:      | " << string((LengthOfP1[19] - (LengthOfP1[8]/2))/2, ' ') << Players[0][8] << string(((LengthOfP1[19] - (LengthOfP1[8]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[8]/2))/2, ' ') << Players[1][8] << string(((LengthOfP2[19] - (LengthOfP2[8]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[8]/2))/2, ' ') << Players[2][8] << string(((LengthOfP3[19] - (LengthOfP3[8]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[8]/2))/2, ' ') << Players[3][8] << string(((LengthOfP4[19] - (LengthOfP4[8]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[8]/2))/2, ' ') << Players[4][8] << string(((LengthOfP5[19] - (LengthOfP5[8]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[8]/2))/2, ' ') << Players[5][8] << string(((LengthOfP6[19] - (LengthOfP6[8]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "10.4 of a kind:     | " << string((LengthOfP1[19] - (LengthOfP1[9]/2))/2, ' ') << Players[0][9] << string(((LengthOfP1[19] - (LengthOfP1[9]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[9]/2))/2, ' ') << Players[1][9] << string(((LengthOfP2[19] - (LengthOfP2[9]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[9]/2))/2, ' ') << Players[2][9] << string(((LengthOfP3[19] - (LengthOfP3[9]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[9]/2))/2, ' ') << Players[3][9] << string(((LengthOfP4[19] - (LengthOfP4[9]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[9]/2))/2, ' ') << Players[4][9] << string(((LengthOfP5[19] - (LengthOfP5[9]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[9]/2))/2, ' ') << Players[5][9] << string(((LengthOfP6[19] - (LengthOfP6[9]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "11.Full house:      | " << string((LengthOfP1[19] - (LengthOfP1[10]/2))/2, ' ') << Players[0][10] << string(((LengthOfP1[19] - (LengthOfP1[10]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[10]/2))/2, ' ') << Players[1][10] << string(((LengthOfP2[19] - (LengthOfP2[10]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[10]/2))/2, ' ') << Players[2][10] << string(((LengthOfP3[19] - (LengthOfP3[10]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[10]/2))/2, ' ') << Players[3][10] << string(((LengthOfP4[19] - (LengthOfP4[10]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[10]/2))/2, ' ') << Players[4][10] << string(((LengthOfP5[19] - (LengthOfP5[10]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[10]/2))/2, ' ') << Players[5][10] << string(((LengthOfP6[19] - (LengthOfP6[10]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "12.Small straight:  | " << string((LengthOfP1[19] - (LengthOfP1[11]/2))/2, ' ') << Players[0][11] << string(((LengthOfP1[19] - (LengthOfP1[11]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[11]/2))/2, ' ') << Players[1][11] << string(((LengthOfP2[19] - (LengthOfP2[11]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[11]/2))/2, ' ') << Players[2][11] << string(((LengthOfP3[19] - (LengthOfP3[11]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[11]/2))/2, ' ') << Players[3][11] << string(((LengthOfP4[19] - (LengthOfP4[11]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[11]/2))/2, ' ') << Players[4][11] << string(((LengthOfP5[19] - (LengthOfP5[11]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[11]/2))/2, ' ') << Players[5][11] << string(((LengthOfP6[19] - (LengthOfP6[11]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "13.Large straight:  | " << string((LengthOfP1[19] - (LengthOfP1[12]/2))/2, ' ') << Players[0][12] << string(((LengthOfP1[19] - (LengthOfP1[12]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[12]/2))/2, ' ') << Players[1][12] << string(((LengthOfP2[19] - (LengthOfP2[12]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[12]/2))/2, ' ') << Players[2][12] << string(((LengthOfP3[19] - (LengthOfP3[12]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[12]/2))/2, ' ') << Players[3][12] << string(((LengthOfP4[19] - (LengthOfP4[12]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[12]/2))/2, ' ') << Players[4][12] << string(((LengthOfP5[19] - (LengthOfP5[12]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[12]/2))/2, ' ') << Players[5][12] << string(((LengthOfP6[19] - (LengthOfP6[12]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "14.Chance:          | " << string((LengthOfP1[19] - (LengthOfP1[13]/2))/2, ' ') << Players[0][13] << string(((LengthOfP1[19] - (LengthOfP1[13]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[13]/2))/2, ' ') << Players[1][13] << string(((LengthOfP2[19] - (LengthOfP2[13]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[13]/2))/2, ' ') << Players[2][13] << string(((LengthOfP3[19] - (LengthOfP3[13]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[13]/2))/2, ' ') << Players[3][13] << string(((LengthOfP4[19] - (LengthOfP4[13]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[13]/2))/2, ' ') << Players[4][13] << string(((LengthOfP5[19] - (LengthOfP5[13]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[13]/2))/2, ' ') << Players[5][13] << string(((LengthOfP6[19] - (LengthOfP6[13]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "15.Yahtzee:         | " << string((LengthOfP1[19] - (LengthOfP1[14]/2))/2, ' ') << Players[0][14] << string(((LengthOfP1[19] - (LengthOfP1[14]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[14]/2))/2, ' ') << Players[1][14] << string(((LengthOfP2[19] - (LengthOfP2[14]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[14]/2))/2, ' ') << Players[2][14] << string(((LengthOfP3[19] - (LengthOfP3[14]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[14]/2))/2, ' ') << Players[3][14] << string(((LengthOfP4[19] - (LengthOfP4[14]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[14]/2))/2, ' ') << Players[4][14] << string(((LengthOfP5[19] - (LengthOfP5[14]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[14]/2))/2, ' ') << Players[5][14] << string(((LengthOfP6[19] - (LengthOfP6[14]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "Your upper score:   | " << string((LengthOfP1[19] - (LengthOfP1[15]/2))/2, ' ') << Players[0][15] << string(((LengthOfP1[19] - (LengthOfP1[15]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[15]/2))/2, ' ') << Players[1][15] << string(((LengthOfP2[19] - (LengthOfP2[15]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[15]/2))/2, ' ') << Players[2][15] << string(((LengthOfP3[19] - (LengthOfP3[15]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[15]/2))/2, ' ') << Players[3][15] << string(((LengthOfP4[19] - (LengthOfP4[15]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[15]/2))/2, ' ') << Players[4][15] << string(((LengthOfP5[19] - (LengthOfP5[15]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[15]/2))/2, ' ') << Players[5][15] << string(((LengthOfP6[19] - (LengthOfP6[15]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "Your lower score:   | " << string((LengthOfP1[19] - (LengthOfP1[16]/2))/2, ' ') << Players[0][16] << string(((LengthOfP1[19] - (LengthOfP1[16]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[16]/2))/2, ' ') << Players[1][16] << string(((LengthOfP2[19] - (LengthOfP2[16]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[16]/2))/2, ' ') << Players[2][16] << string(((LengthOfP3[19] - (LengthOfP3[16]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[16]/2))/2, ' ') << Players[3][16] << string(((LengthOfP4[19] - (LengthOfP4[16]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[16]/2))/2, ' ') << Players[4][16] << string(((LengthOfP5[19] - (LengthOfP5[16]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[16]/2))/2, ' ') << Players[5][16] << string(((LengthOfP6[19] - (LengthOfP6[16]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    
    cout << "Your total score:   | " << string((LengthOfP1[19] - (LengthOfP1[17]/2))/2, ' ') << Players[0][17] << string(((LengthOfP1[19] - (LengthOfP1[17]/2))/2) + LengthOfP1[20], ' ') << "| " << string((LengthOfP2[19] - (LengthOfP2[17]/2))/2, ' ') << Players[1][17] << string(((LengthOfP2[19] - (LengthOfP2[17]/2))/2) + LengthOfP2[20], ' ') << "| " << string((LengthOfP3[19] - (LengthOfP3[17]/2))/2, ' ') << Players[2][17] << string(((LengthOfP3[19] - (LengthOfP3[17]/2))/2) + LengthOfP3[20], ' ') << "| " << string((LengthOfP4[19] - (LengthOfP4[17]/2))/2, ' ') << Players[3][17] << string(((LengthOfP4[19] - (LengthOfP4[17]/2))/2) + LengthOfP4[20], ' ') << "| " << string((LengthOfP5[19] - (LengthOfP5[17]/2))/2, ' ') << Players[4][17] << string(((LengthOfP5[19] - (LengthOfP5[17]/2))/2) + LengthOfP5[20], ' ') << "| " << string((LengthOfP6[19] - (LengthOfP6[17]/2))/2, ' ') << Players[5][17] << string(((LengthOfP6[19] - (LengthOfP6[17]/2))/2) + LengthOfP6[20], ' ') << "| " << endl;
    cout << "---------------------------------------" << string((LengthOfP1[19] + LengthOfP2[19] + LengthOfP3[19] + LengthOfP4[19] + LengthOfP5[19] + LengthOfP6[19]), '-') << endl;
}
