#include "MCTS.h"

#include <Game.h>

#include <random>

using namespace std;

MCTS::MCTS(Game &game) : game(game) {
}

Game MCTS::randomMove(Game &gameRollout) {
    std::uniform_int_distribution<int> colDist(0, gameRollout.nonEmptyColumns.size() - 1);
    const int col_i = gameRollout.nonEmptyColumns[colDist(rd)];

    std::uniform_int_distribution<int> rowDist(0, gameRollout.grid[col_i].size() - 1);
    const int row_i = rowDist(rd);

    gameRollout.remove(col_i, row_i);
    return gameRollout;
}
}
