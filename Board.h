#include <iostream>
#include <vector>

#include "Dice.h"

using namespace std;

class Board{
public:
    int firstPlayer();
  /*  map<int, string> getOptionalTokens(Dice dice);
    map<int, string> getTargetTokens(int tokenIndex, int spaces);*/
    void moveToken(int tokenIndex);

    void printBoard();


private:
    const int SPACES = 25;
    const int MAX_STONES = 15;
    vector<int> player1Board;
    vector<int> player2Board;
    Dice currentDice;
};