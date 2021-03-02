
#include "Dice.h"

void Dice::diceRoll(){
    srand((unsigned)time(nullptr));

    roll1 = rand() % 6 + 1;
    roll2 = rand() % 6 + 1;
    cout << roll1 << " " << roll2;
}

