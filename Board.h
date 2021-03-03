#include <iostream>
#include <vector>
#include <map>

#include "Dice.h"

#pragma once

using namespace std;

class Board {
public:
    Board(char symbol1, char symbol2);

    int decideFirstPlayer();

    map<int, string> getOptionalTokens(Dice dice);

    map<int, string> getTargetTokens(int tokenIndex, int spaces);

    void moveToken(int playerIndex, int fromIndex, int toIndex);

    void printBoard();


private:
    const int SPACES = 25;
    const int MAX_STONES = 15;
    vector<int> player1Board;
    vector<int> player2Board;
    Dice currentDice;
    char player1Symbol;
    char player2Symbol;
};

