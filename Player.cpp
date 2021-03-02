#include <iostream>
#include <map>

#include "Player.h"

using namespace std;

Player::Player(string playerName, string playerSymbol)
        :name(playerName), symbol(playerSymbol){}

string Player::getName(){
    return name;
}

string Player::getSymbol(){
    return symbol;
}

Dice Player::ClickDice(){
    return Dice();
}

// int Player::SelectToken(map<int, string> tokens){

//   return 0;
// }

// int Player::MoveToken(map<int, string> tokens){

// }

// void Player::printList(map<int,string> allOptions, std::string title){
//   cout << title << endl;
//   for(iterator<int, string> it = allOptions.begin(); ++it){

//   }
// }