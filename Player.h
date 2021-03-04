#pragma once
#include <iostream>
#include "Dice.h"
#include <vector>
#include <set>

using namespace std;


class Player {
public:
    Player(string name, char symbol);

    string getName();

    void setName(string name);

    char getSymbol();

    void setSymbol(char symbol);

    vector<int> SelectToken(set<pair<int, string>> tokens);

    int MoveToken(set<pair<int, string>> tokens);

    void printMap(set<pair<int, string>> allOptions, string title);

    void setPlayerIndex(int index);

    int getPlayerIndex();

private:
    string name;
    int playerIndex;
    char symbol;
    const string TITLE_SELECT = "Select a token: ";
    const string TITLE_MOVE = "Select target space: ";
};