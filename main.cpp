#include <iostream>
#include <sstream>

#include "Board.h"


using namespace std;

enum Symbol {
    ASTERISK = '*', DOLLAR = '$', PERCENT = '%', PLUS = '+', AT = '@', POUND = '#'
};

void printSymbols() {
    cout << "Symbol for selection: " << endl;
    cout << "1:" << (char) ASTERISK
         << ", 2:" << (char) DOLLAR
         << ", 3:" << (char) PERCENT
         << ", 4:" << (char) PLUS
         << ", 5:" << (char) AT
         << ", 6:" << (char) POUND
         << endl;
}

char getSymbolValue(int index) {
    switch (index) {
        case 1:
            return (char) Symbol::ASTERISK;
        case 2:
            return (char) Symbol::DOLLAR;
        case 3:
            return (char) Symbol::PERCENT;
        case 4:
            return (char) Symbol::PLUS;
        case 5:
            return (char) Symbol::AT;
        case 6:
            return (char) Symbol::POUND;
    }
}

int getValidSymbolIndex() {
    printSymbols();
    int indexOfSymbol;

    string indexOfSymbolStr;

    getline(cin, indexOfSymbolStr);
    stringstream(indexOfSymbolStr) >> indexOfSymbol;

    while (indexOfSymbol < 1 || indexOfSymbol > 6) {
        cout << "No such symbol index!" << endl;
        printSymbols();
        getline(cin, indexOfSymbolStr);
        stringstream(indexOfSymbolStr) >> indexOfSymbol;
    }
    return indexOfSymbol;
}

Player createPlayer(int index) {
    cout << "Input name of the " << index << " player: " << endl;
    string playerName;
    getline(cin, playerName);

    int indexOfSymbol = getValidSymbolIndex();

    Player player(playerName, getSymbolValue(indexOfSymbol));
    return player;
}

int main() {

    Player playerOne = createPlayer(1);
    Player playerTwo = createPlayer(2);

    string playerName;
    while (playerTwo.getName() == playerOne.getName()) {
        cout << "Player name exists, please select another name (" << playerOne.getName() << "):" << endl;
        getline(cin, playerName);
        playerTwo.setName(playerName);
    }

    int indexOfSymbol;
    while (playerTwo.getSymbol() == playerOne.getSymbol()) {
        cout << "The symbol has been selected by player one (" << playerOne.getSymbol()
             << "), please pick another one!" << endl;
        indexOfSymbol = getValidSymbolIndex();
        playerTwo.setSymbol(getSymbolValue(indexOfSymbol));
    }

    Board board(playerOne, playerTwo);
    board.printBoard();

    board.moveToken(0, 17, 22);
    board.printBoard();

    Dice dice;
    cout << "dice result: " << dice.getRoll1() << ", " << dice.getRoll2() << ", " << dice.getRollsSum() << endl;
    board.getTokensForMoving(0, dice);

    return 0;
}

