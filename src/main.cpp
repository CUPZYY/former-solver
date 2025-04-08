#include <iostream>
#include <vector>

#include "FileParser.h"
#include "Game.h"
#include "MCTS.h"
using namespace std;

/*
    1: Blue
    2: Green
    3: Orange
    4: Pink
*/

vector<vector<int>> grid;

int main() {
    grid = fileToGrid("input.txt");
    Game game(grid);
    MCTS solver(game);
    vector<MCTS::Move> moves = solver.solve(550);
};
