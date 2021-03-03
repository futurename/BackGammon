#include <iostream>
#include "Dice.h"
#include <vector>
#include <map>

#pragma once

using namespace std;

class Player {
public:
    Player(string name, char symbol);

    string getName();

    void setName(string name);

    char getSymbol();

    void setSymbol(char symbol);

    Dice ClickDice();

    int SelectToken(map<int, string> tokens);

    int MoveToken(map<int, string> tokens);

    void printMap(map<int, string> allOptions, string title);

private:
    string name;
    char symbol;
    const string TITLE_SELECT = "Select a token: ";
    const string TITLE_MOVE = "Select target space: ";
};