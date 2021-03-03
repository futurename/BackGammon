#pragma once
#include <iostream>
#include <vector>
#include <set>

#include "Player.h"

using namespace std;

class Board {
public:
    Board(Player &player1, Player &player2);

    int decideFirstPlayer();

    set<pair<int, string>> getTokensForMoving(int playerIndex, Dice dice);

    set<pair<int, string>> getTargetTokens(int tokenIndex, int spaces);

    void moveToken(int playerIndex, int fromIndex, int toIndex);

    void printBoard();

    void ClickDice(Board &board, int playerIndex);

private:
    const int SPACES = 25;
    vector<int> player1Board;
    vector<int> player2Board;
    Dice currentDice;
    Player *player1;
    Player *player2;
};

