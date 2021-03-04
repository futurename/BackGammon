/*
 Title: Backgammon Assignment
 Authors: Wei Wang & Kishan Patel
*/

#include <iomanip>
#include <sstream>
#include "Board.h"

Board::Board(Player &player1, Player &player2) {
    const int MAX_SPACE = 25;

    this->player1 = &player1;
    this->player2 = &player2;

    player1Board.resize(MAX_SPACE);
    player2Board.resize(MAX_SPACE);

    player1Board.at(1) = 2;
    player1Board.at(12) = 5;
    player1Board.at(17) = 3;
    player1Board.at(19) = 5;

    //for testing
    player2Board.at(3) = 1;

    player2Board.at(1) = 2;
    player2Board.at(12) = 5;
    player2Board.at(17) = 3;
    player2Board.at(19) = 5;

}

void Board::printBoard() {
    const int BOARD_WIDTH = 50;
    const int BOARD_MIDDLE = 15;
    const int BOARD_BAR = 10;

    stringstream ss;

    ss << player1->getName() << ":Left\'" << player1->getSymbol() << "\' VS. " << player2->getName() << ":(Right)\'"
       << player2->getSymbol() << "\'";

    cout << endl << setw((int) (BOARD_WIDTH - ss.str().size()) / 2) << "" << ss.str() << endl;
    ss.str("");

    cout << setfill('-') << setw(BOARD_WIDTH) << "" << endl;
    cout.fill(' ');


    for (int i = 12; i > 0; i--) {
        ss << i << "(" << SPACES - i << ") ";
        cout << setw(BOARD_BAR) << right << ss.str();
        ss.str("");
        bool hasData = false;

        if (player1Board.at(i) > 0) {
            hasData = true;
            for (int j = 0; j < player1Board.at(i); j++) {
                ss << player1->getSymbol();
            }
            cout << left << setw(BOARD_MIDDLE) << ss.str();
            ss.str("");
        }
        if (player2Board.at(SPACES - i) > 0) {
            hasData = true;
            for (int j = 0; j < player2Board.at(SPACES - i); j++) {
                ss << player2->getSymbol();
            }
            cout << left << setw(BOARD_MIDDLE) << ss.str();
            ss.str("");
        }

        if (!hasData) {
            cout << setw(BOARD_MIDDLE) << "";
        }
        hasData = false;

        if (player1Board.at(SPACES - i) > 0) {
            hasData = true;
            for (int j = 0; j < player1Board.at(SPACES - i); j++) {
                ss << player1->getSymbol();
            }
            cout << right << setw(BOARD_MIDDLE) << ss.str();
            ss.str("");
        }
        if (player2Board.at(i) > 0) {
            hasData = true;
            for (int j = 0; j < player2Board.at(i); j++) {
                ss << player2->getSymbol();
            }
            cout << right << setw(BOARD_MIDDLE) << ss.str();
            ss.str("");
        }

        if (!hasData) {
            cout << setw(BOARD_MIDDLE) << "";
        }

        ss << "(" << (i) << ")" << SPACES - i;
        cout << setfill(' ') << setw(2) << "" << setw(BOARD_BAR - 2) << left << ss.str() << endl;
        ss.str("");
    }

    cout << setw(BOARD_BAR) << left << "Captured:";
    if (player1Board.at(0) > 0) {
        for (int i = 0; i < player1Board.at(0); i++) {
            ss << player1->getSymbol();
        }
        cout << setw(BOARD_MIDDLE) << right << ss.str();
        ss.str("");
    } else {
        cout << setw(BOARD_MIDDLE) << "";
    }

    if (player2Board.at(0) > 0) {
        for (int i = 0; i < player2Board.at(0); i++) {
            ss << player2->getSymbol();
        }
        cout << setw(BOARD_MIDDLE) << left << ss.str();
        ss.str("");
    }

    cout << endl;
    cout << setfill('-') << setw(BOARD_WIDTH) << "" << endl << endl;
    cout.fill(' ');
}

void Board::moveToken(int playerIndex, int fromIndex, int toIndex) {
    Player *curPlayer = playerIndex == 0 ? player1 : player2;
    vector<int> &curPlayerVector = playerIndex == 0 ? player1Board : player2Board;
    vector<int> &oppPlayerVector = playerIndex == 0 ? player2Board : player1Board;

    //FIXEME check whether there are more than one stone at the target position
    if (oppPlayerVector.at(toIndex) > 1) {
        cout << "Error! there are more than One opponent tokens at index: " << toIndex << endl;
    } else if (oppPlayerVector.at(SPACES - toIndex) == 1) {
        oppPlayerVector.at(SPACES - toIndex)--;
        oppPlayerVector.at(0)++;
    }

    curPlayerVector.at(fromIndex)--;
    curPlayerVector.at(toIndex)++;

    cout << curPlayer->getName() << " moves from <" << fromIndex << "> to <" << toIndex << ">." << endl;
}

set<pair<int, string>> Board::getTokensForMoving(int playerIndex, int roll1, int roll2) {
    set<pair<int, string>> result;
    vector<int> &curPlayerTokens = playerIndex == 0 ? player1Board : player2Board;
    vector<int> &oppPlayerTokens = playerIndex == 0 ? player2Board : player1Board;

    stringstream ss;

    //Iterate all token index and check whether it can move with steps of roll1, roll2 and sum.
    for (int i = 1; i < SPACES; i++) {
        ss.str("");
        if (curPlayerTokens.at(i) > 0) {
            if (i + roll1 < SPACES && oppPlayerTokens.at(i + roll1) <= 1) {
                ss << i << " -> " << i + roll1 << ", ";
            }
            if (i + roll2 < SPACES && oppPlayerTokens.at(i + roll2) <= 1) {
                ss << i << " -> " << i + roll2 << ", ";
            }
            result.insert(pair<int, string>(i, ss.str()));
        }
    }
    return result;
}

set<pair<int, string>> Board::getTokensForMoving(int playerIndex, int roll2) {
    set<pair<int, string>> result;
    vector<int> &curPlayerTokens = playerIndex == 0 ? player1Board : player2Board;
    vector<int> &oppPlayerTokens = playerIndex == 0 ? player2Board : player1Board;

    stringstream ss;

    //Iterate all token index and check whether it can move with steps of roll1, roll2 and sum.
    for (int i = 1; i < SPACES; i++) {
        ss.str("");
        if (curPlayerTokens.at(i) > 0) {
            if (i + roll2 < SPACES && oppPlayerTokens.at(SPACES -(i + roll2)) <= 1) {
                ss << i << " -> " << i + roll2 << ", ";
            }
            result.insert(pair<int, string>(i, ss.str()));
            ss.str("");
        }
    }
    return result;
}

void Board::playing(int playerIndex) {
    bool player1Turn = playerIndex == 0 ? true : false;
    Player *curPlayer = player1Turn ? player1 : player2;
    vector<int> &curTokens = player1Turn ? player1Board: player2Board;

    while (true) {
        Dice dice;
        Player *curPlayer = player1Turn ? player1 : player2;
        vector<int> &curTokens = player1Turn ? player1Board: player2Board;

        set<pair<int, string>> moveSet;

        cout << ">>> Player" << (player1Turn ? " 1 " :" 2 ") << ": " << curPlayer->getName() << " <<<" << endl;

        //first roll processing
        if (player1Turn) {
            moveSet = getTokensForMoving(player1->getPlayerIndex(), dice.getRoll1(), dice.getRoll2());
        } else {
            moveSet = getTokensForMoving(player2->getPlayerIndex(), dice.getRoll1(), dice.getRoll2());
        }

        vector<int> selection = curPlayer->SelectToken(moveSet);
        moveToken(curPlayer->getPlayerIndex(), selection.at(0), selection.at(1));

        printBoard();

        //second roll processing
        int unSelRoll = dice.getRoll1() == selection.at(1) - selection.at(0) ? dice.getRoll2() : dice.getRoll1();
        if (player1Turn) {
            moveSet = getTokensForMoving(player1->getPlayerIndex(), unSelRoll);
        } else {
            moveSet = getTokensForMoving(player2->getPlayerIndex(), unSelRoll);
        }

        selection = curPlayer->SelectToken(moveSet);
        moveToken(curPlayer->getPlayerIndex(), selection.at(0), selection.at(1));

        printBoard();

        player1Turn = !player1Turn;
    }
}



