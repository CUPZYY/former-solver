#include "MCTS.h"

#include <Game.h>

#include <random>
#include <iostream>
#include <utility>

using namespace std;

MCTS::MCTS(Game &game) : game(game) {
}

vector<MCTS::Move> MCTS::solve(const int iterations) {
    vector<Move> moves = {};
    while (!game.isFinished()) {
        Move move = findNextMove(iterations);
        game.remove(move.col, move.row);
        moves.push_back(move);
        cout << moves.size() << ": Made move: (" << move.col << ", " << move.row << ") with and average of " << move.
                moves << " moves left." << endl;
        cout << game.stringify() << endl;
    }
    return moves;
}

MCTS::Move MCTS::findNextMove(const int iterations) {
    // bestMove contains index of column, index of row and the average moves until completion
    Move bestMove = {-1, -1, 1000000};
    for (const int col_i: game.nonEmptyColumns) {
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
    int total = 0;
    for (const vector<int>& col: gameRollout.grid) {
        total += col.size();
    }

    uniform_int_distribution<int> totalDist(0, total - 1);
    const int total_i = totalDist(rd);

    int col_i = 0;
    int row_i = 0;

    int total_left = total_i;
    for (int col_index: gameRollout.nonEmptyColumns) {
        if (gameRollout.grid[col_index].size() > total_left) {
            col_i = col_index;
            row_i = total_left;
            break;
        }
        total_left -= gameRollout.grid[col_index].size();
    }

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
