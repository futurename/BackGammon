/*
 Title: Backgammon Assignment
 Authors: Wei Wang & Kishan Patel
*/

#include <iostream>
#include <sstream>

#include "Board.h"

using namespace std;

// Symbol options for the player to select
enum Symbol {
    ASTERISK = '*', DOLLAR = '$', PERCENT = '%', PLUS = '+', AT = '@', POUND = '#'
};

// Print symbol options to the console
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

// Get symbol value from index selected
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

// Testing validity of symbol selected
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

// Receiving names and creating players
Player createPlayer(int index) {
    cout << "Input name of the " << index << " player: " << endl;
    string playerName;
    getline(cin, playerName);

    int indexOfSymbol = getValidSymbolIndex();

    Player player(playerName, getSymbolValue(indexOfSymbol));
    return player;
}

int main() {

// Creating two player objects and passing their index to createPlayer function
    Player playerOne = createPlayer(1);
    Player playerTwo = createPlayer(2);

// Ensuring no duplicate names are taken
    string playerName;
    while (playerTwo.getName() == playerOne.getName()) {
        cout << "Player name exists, please select another name (" << playerOne.getName() << "):" << endl;
        getline(cin, playerName);
        playerTwo.setName(playerName);
    }

// Ensuring no duplicate symbols are taken
    int indexOfSymbol;
    while (playerTwo.getSymbol() == playerOne.getSymbol()) {
        cout << "The symbol has been selected by player one (" << playerOne.getSymbol()
             << "), please pick another one!" << endl;
        indexOfSymbol = getValidSymbolIndex();
        playerTwo.setSymbol(getSymbolValue(indexOfSymbol));
    }


    playerOne.setPlayerIndex(0);
    playerTwo.setPlayerIndex(1);

    // Creating a board instance with player objects as arguments
    Board board(playerOne, playerTwo);
    board.printBoard();

    board.moveToken(0, 17, 22);
    board.printBoard();

    Dice dice;
    cout << "dice result: " << dice.getRoll1() << ", " << dice.getRoll2() << endl;

    board.getTokensForMoving(0, dice.getRoll1(), dice.getRoll2());
    board.getTokensForMoving(0,  dice.getRoll2());

    board.playing(0);

    return 0;
}

