#include <iostream>
#include "Dice.h"
#include <vector>

using namespace std;

class Player {
public:
    string getName();

    string getSymbol();

    Player(string playerName, string playerSymbol);

    Dice ClickDice();
    // int SelectToken(map<int, string> tokens);
    // int MoveToken(map<int, string> tokens);
    // void printList(map<int, string> allOptions, string title);

private:
    string name;
    string symbol;
    const string TITLE_SELECT = "Select a token: ";
    const string TITLE_MOVE = "Select target space: ";
};