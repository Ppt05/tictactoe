#ifndef AI_H
#define AI_H

#include "logic.h"

struct Move {
    int row, col;
};

int evaluate(const Tictactoe& game) {
    if (game.checkWin(X_CELL))
        return +10;
    else if (game.checkWin(O_CELL))
        return -10;
    return 0;
}

bool isMovesLeft(const Tictactoe& game) {
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (game.board[i][j] == EMPTY_CELL)
                return true;
    return false;
}

int minimax(Tictactoe& game, int depth, bool isMax) {
    int score = evaluate(game);

    if (score == 10)
        return score - depth;

    if (score == -10)
        return score + depth;

    if (!isMovesLeft(game))
        return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (game.board[i][j] == EMPTY_CELL) {
                    game.board[i][j] = X_CELL;
                    best = max(best, minimax(game, depth + 1, !isMax));
                    game.board[i][j] = EMPTY_CELL;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (game.board[i][j] == EMPTY_CELL) {
                    game.board[i][j] = O_CELL;
                    best = min(best, minimax(game, depth + 1, !isMax));
                    game.board[i][j] = EMPTY_CELL;
                }
            }
        }
        return best;
    }
}

Move findBestMove(Tictactoe& game) {
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game.board[i][j] == EMPTY_CELL) {
                game.board[i][j] = X_CELL;
                int moveVal = minimax(game, 0, false);
                game.board[i][j] = EMPTY_CELL;

                if (moveVal > bestVal) {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

#endif // AI_H

