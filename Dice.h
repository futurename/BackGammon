#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Dice {
public:
    Dice();

    void diceRoll();

    int getRoll1();

    int getRoll2();

    int getRollsSum();

private:
    int roll1;
    int roll2;
};