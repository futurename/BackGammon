#include <iostream>
#include <vector>
#include <map>

#include "Dice.h"

#pragma once

using namespace std;

class Board {
public:
    Board();

    int decideFirstPlayer();

    map<int, string> getOptionalTokens(Dice dice);

    map<int, string> getTargetTokens(int tokenIndex, int spaces);

    void moveToken(int tokenIndex);

    void printBoard(char player1Symbol, char player2Symbol);


private:
    const int SPACES = 25;
    const int MAX_STONES = 15;
    vector<int> player1Board;
    vector<int> player2Board;
    Dice currentDice;
};

