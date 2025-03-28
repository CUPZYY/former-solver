#include <Game.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

Game::Game(const vector<vector<int> > &grid) {
    this->grid = grid;
    rowSize = grid.size();
    colSize = grid[0].size();
};

string Game::stringify() {
    string res = "";
    for (int col = 0; col < colSize; col++) {
        for (int row = 0; row < rowSize; row++) {
            if (colSize - grid[row].size() <= col) {
                res +=
                    to_string(grid[row][col - (colSize - grid[row].size())]) +
                    " ";
            } else {
                res += "  ";
            }
        }
        res += "\n";
    }
    return res;
}

void Game::remove(int col, int row, bool gravity = true) {
    int type = grid[col][row];
    grid[col][row] = 0;
    checkNeighbours(col, row, type);
    if (gravity) {
        gravitate();
    }
}

void Game::checkNeighbours(int col, int row, int type) {
    if (isValid(col, row + 1) && (grid[col][row + 1] == type))
        remove(col, row + 1, false);
    if (isValid(col, row - 1) && (grid[col][row - 1] == type))
        remove(col, row - 1, false);
    if (isValid(col + 1, row) && (grid[col + 1][row] == type))
        remove(col + 1, row, false);
    if (isValid(col - 1, row) && (grid[col - 1][row] == type))
        remove(col - 1, row, false);
}

void Game::gravitate() {
    for (int i = 0; i < grid.size(); i++) {
        grid[i].erase(std::remove(grid[i].begin(), grid[i].end(), 0),
                      grid[i].end());
    }
}

bool Game::isValid(int col, int row) {
    return !((rowSize <= col) || (col < 0) ||
             (grid[col].size()) <= colSize - (row + 1) || (row < 0));
}