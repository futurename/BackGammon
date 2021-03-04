#include <iostream>
#include <map>

#include "Player.h"
#include "Board.h"

using namespace std;

string Player::getName() {
    return name;
}

char Player::getSymbol() {
    return symbol;
}

int Player::getPlayerIndex() {
    return playerIndex;
}

vector<int> Player::SelectToken(set<pair<int, string>> tokens){
    printMap(tokens, TITLE_SELECT);
    int fromIndex;
    int toIndex;
    vector<int> moveSelection;

    cout << "Please input fromIndex (space) toIndex(1 2): " << endl;
    cout << "Enter the index of the token you wish to move";
    cin >> fromIndex;
    cout << "Enter the index of your target space: " << endl;
    cin >> toIndex;

    moveSelection.push_back(fromIndex);
    moveSelection.push_back(toIndex);

    return moveSelection;

    // Board::moveToken(getPlayerIndex(), fromIndex, toIndex);
}

int Player::MoveToken(set<pair<int, string>> tokens) {
    printMap(tokens, TITLE_MOVE);
    int userInput;
    cin >> userInput;
    return userInput;
}

void Player::printMap(set<pair<int, string>> allOptions, std::string title) {
    cout << title << endl;

    for (auto &allOption : allOptions) {
        cout << "Index-> " << allOption.first << ", Target indexes: " << allOption.second << endl;
    }

    cout << "Your choice: " << endl;
}

Player::Player(string name, char symbol) {
    this->name = name;
    this->symbol = symbol;
}

void Player::setSymbol(char symbol) {
    this->symbol = symbol;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setPlayerIndex(int index){
    playerIndex = index;
}



