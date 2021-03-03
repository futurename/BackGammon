#include <iostream>
#include <vector>
#include <map>

#include "Dice.h"
#include "Player.h"

#pragma once

using namespace std;

class Board {
public:
    Board(Player &player1, Player &player2);

    int decideFirstPlayer();

    map<int, string> getTokensForMoving(int playerIndex, Dice dice);

    map<int, string> getTargetTokens(int tokenIndex, int spaces);

    void moveToken(int playerIndex, int fromIndex, int toIndex);

    void printBoard();

private:
    const int SPACES = 25;
    vector<int> player1Board;
    vector<int> player2Board;
    Dice currentDice;
    Player *player1;
    Player *player2;
};

