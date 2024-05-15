
#ifndef LOGIC_H
#define LOGIC_H
#include <iostream>

#define BOARD_SIZE 3
#define EMPTY_CELL ' '
#define O_CELL 'o'
#define X_CELL 'x'

using namespace std;

struct Tictactoe {
    char board[BOARD_SIZE][BOARD_SIZE];
    char nextMove = O_CELL;
    bool gameOver = false;

    void init() {
        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++) board[i][j] = EMPTY_CELL;
    }

    void reset() {
        init();
        nextMove = O_CELL;
        gameOver = false;
    }

    bool isBoardFull() const {
        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++)
                if (board[i][j] == EMPTY_CELL) return false;
        return true;
    }

    bool isValidMove(int row, int column) {
        return row >= 0 && row < BOARD_SIZE && column >= 0 && column < BOARD_SIZE && board[row][column] == EMPTY_CELL;
    }

    bool checkWin(char player) const {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        }
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[0][j] == player && board[1][j] == player && board[2][j] == player) return true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
        return false;
    }

    void move(int row, int column) {
        if (!gameOver && isValidMove(row, column)) {
            board[row][column] = nextMove;
            if (checkWin(nextMove)) {
                cout << "Player " << nextMove << " wins!" << endl;
                gameOver = true;
            } else if (isBoardFull()) {
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;
            }
        }
    }

    void restart() {
        init();
        nextMove = O_CELL;
        gameOver = false;
    }
};

#endif


