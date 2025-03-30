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

string Game::stringify() const {
    string res;
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

void Game::remove(const int col, const int row, const bool isDirectCall) {
    const int type = grid[col][row];
    grid[col][row] = 0;
    checkNeighbours(col, row, type);
    if (isDirectCall) {
        for (int col_i = 0; col_i < rowSize; col_i++) {
            gravitate(grid[col_i]);
            if (grid[col_i].empty()) {
                grid.erase(grid.begin() + col_i);
            }
        }
    }
}

bool Game::isFinished() const { return grid.empty();}

void Game::checkNeighbours(const int col, const int row, const int type) {
    if (isValid(col, row + 1) && (grid[col][row + 1] == type))
        remove(col, row + 1, false);
    if (isValid(col, row - 1) && (grid[col][row - 1] == type))
        remove(col, row - 1, false);
    if (isValid(col + 1, row) && (grid[col + 1][row] == type))
        remove(col + 1, row, false);
    if (isValid(col - 1, row) && (grid[col - 1][row] == type))
        remove(col - 1, row, false);
}

void Game::gravitate(vector<int> &col) {
    col.erase(std::remove(col.begin(), col.end(), 0), col.end());
}

bool Game::isValid(const int col, const int row) const {
    return !((rowSize <= col) || (col < 0) ||
             (grid[col].size()) <= colSize - (row + 1) || (row < 0));
}
