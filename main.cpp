#include <iostream>

#include "Game.cpp"
using namespace std;

/*
    1: Blue
    2: Green
    3: Orange
    4: Pink
*/

vector<vector<int> > grid = {
    {1, 2, 1, 2, 4, 1, 3, 3, 1}, {2, 3, 3, 1, 3, 1, 1, 3, 2},
    {1, 4, 4, 1, 4, 4, 2, 3, 1}, {4, 3, 2, 3, 4, 3, 1, 4, 1},
    {3, 4, 3, 3, 2, 3, 2, 3, 4}, {3, 2, 4, 4, 2, 3, 4, 2, 3},
    {4, 2, 3, 1, 3, 2, 4, 1, 2}};

Game game(grid);

int main() { cout << game.stringify(); };
