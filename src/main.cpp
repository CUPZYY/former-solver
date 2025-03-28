#include <iostream>
#include <vector>

#include "Game.h"
#include "FileParser.h"
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
    cout << game.stringify();
};
