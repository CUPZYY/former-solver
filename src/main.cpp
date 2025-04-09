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

vector<vector<int> > grid;

int main(int argc, char *argv[]) {
    const chrono::time_point<chrono::steady_clock> start = chrono::high_resolution_clock::now();

    grid = fileToGrid(argv[1]);
    Game game(grid);
    MCTS solver(game);
    vector<MCTS::Move> moves = solver.solve(550);

    const chrono::time_point<chrono::steady_clock> end = chrono::high_resolution_clock::now();
    const chrono::duration<double> elapsed = end - start;

    cout << "Finished using " << moves.size() << " moves in " << elapsed.count() << " seconds." << endl;
};
