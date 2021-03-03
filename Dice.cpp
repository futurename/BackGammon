
#include "Dice.h"

void Dice::diceRoll(){
    srand((unsigned)time(nullptr));

    roll1 = rand() % 6 + 1;
    roll2 = rand() % 6 + 1;
}

Dice::Dice() {
    srand((unsigned)time(nullptr));

    roll1 = rand() % 6 + 1;
    roll2 = rand() % 6 + 1;
}

int Dice::getRoll1() {
    return roll1;
}

int Dice::getRoll2() {
    return roll2;
}
