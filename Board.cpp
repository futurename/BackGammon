/*
 Created by Wei Wang on 3/2/2021 002.
*/

#include <iomanip>
#include <sstream>
#include "Board.h"


Board::Board(char symbol1, char symbol2) {
    const int MAX_SPACE = 25;

    player1Symbol = symbol1;
    player2Symbol = symbol2;

    player1Board.resize(MAX_SPACE);
    player2Board.resize(MAX_SPACE);

    player1Board.at(1) = 2;
    player1Board.at(12) = 5;
    player1Board.at(17) = 3;
    player1Board.at(19) = 5;

    player2Board.at(1) = 2;
    player2Board.at(12) = 5;
    player2Board.at(17) = 3;
    player2Board.at(19) = 5;
}

void Board::printBoard() {
    const int BOARD_WIDTH = 38;
    const int BOARD_MIDDLE = 15;

    cout << setfill('-') << setw(BOARD_WIDTH) << "" << endl;
    cout.fill(' ');
    stringstream ss;

    for(int i = 12; i >0; i--) {
        ss << i << "(" << SPACES - i <<") ";
        cout << setw(8) << right<< ss.str();
        ss.str("");

        if (player1Board.at(i) > 0) {
            for (int j = 0; j < player1Board.at(i); j++) {
                ss << player1Symbol;
            }
            cout << left << setw(BOARD_MIDDLE) << ss.str();
            ss.str("");
        }
        if (player2Board.at(SPACES - i) > 0) {
            for (int j = 0; j < player2Board.at(SPACES - i); j++) {
                ss <<  player2Symbol;
            }
            cout <<  left << setw(BOARD_MIDDLE) <<ss.str();
            ss.str("");
        }

        if (player1Board.at(SPACES - i) > 0) {
            for (int j = 0; j < player1Board.at(SPACES - i); j++) {
                ss <<  player1Symbol;
            }
            cout <<  right << setw(BOARD_MIDDLE) << ss.str();
            ss.str("");
        }
        if (player2Board.at(i) > 0) {
            for (int j = 0; j < player2Board.at(i); j++) {
                ss <<  player2Symbol;
            }
            cout <<  right << setw(BOARD_MIDDLE) << ss.str();
            ss.str("");
        }

        cout << endl;
    }
    cout << setfill('-') << setw(BOARD_WIDTH) << "" << endl << endl;
    cout.fill(' ');
}

void Board::moveToken(int playerIndex, int fromIndex, int toIndex) {
    vector<int>& curPlayer = playerIndex  == 0? player1Board : player2Board;
    curPlayer.at(fromIndex)--;
    curPlayer.at(toIndex) ++;
}
