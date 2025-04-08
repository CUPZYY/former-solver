#include "MCTS.h"

#include <Game.h>

#include <random>

using namespace std;

MCTS::MCTS(Game &game) : game(game) {
}

MCTS::Move MCTS::findNextMove(const int iterations) {
    // bestMove contains index of column, index of row and the average moves until completion
    Move bestMove = {-1, -1, 1000000};
    for (const int col_i : game.nonEmptyColumns) {
        vector<int> col = game.grid[col_i];
        for (int row_i = 0; row_i < col.size(); row_i++) {
            Game gameRollout = game;
            gameRollout.remove(col_i, row_i);
            const double moves = simulate(gameRollout, iterations);
            if (moves < bestMove.moves) {
                bestMove = {col_i, row_i, moves};
            }
        }
    }
    return bestMove;
}

Game MCTS::randomMove(Game &gameRollout) {
    std::uniform_int_distribution<int> colDist(0, gameRollout.nonEmptyColumns.size() - 1);
    const int col_i = gameRollout.nonEmptyColumns[colDist(rd)];

    std::uniform_int_distribution<int> rowDist(0, gameRollout.grid[col_i].size() - 1);
    const int row_i = rowDist(rd);

    gameRollout.remove(col_i, row_i);
    return gameRollout;
}

double MCTS::simulate(const Game &gameRollout, const int iterations) {
    double movesTotal = 0;
    for (int i = 0; i < iterations; i++) {
        int moves = 0;
        Game gameRolloutIteration = gameRollout;
        while (!gameRolloutIteration.isFinished()) {
            randomMove(gameRolloutIteration);
            moves++;
        }
        movesTotal += moves;
    }
    return movesTotal / iterations;
}
