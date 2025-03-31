#include "MCTS.h"

#include <Game.h>

#include <random>

using namespace std;

MCTS::MCTS(Game &game) : game(game) {
}

    std::uniform_int_distribution<int> colDist(0, game.nonEmptyColumns.size() - 1);
    const int col_i = game.nonEmptyColumns[colDist(rd)];

    std::uniform_int_distribution<int> rowDist(0, game.grid[col_i].size() - 1);
    const int row_i = rowDist(rd);

    game.remove(col_i, row_i);
    return game;
}
