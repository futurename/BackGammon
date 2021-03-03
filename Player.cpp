#include <iostream>
#include <map>

#include "Player.h"

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

int Player::SelectToken(map<int, string> tokens) {
    printMap(tokens, TITLE_SELECT);
    int userInput;
    cin >> userInput;
    return userInput;
}

int Player::MoveToken(map<int, string> tokens) {
    printMap(tokens, TITLE_MOVE);
    int userInput;
    cin >> userInput;
    return userInput;
}

void Player::printMap(map<int, string> allOptions, std::string title) {
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



