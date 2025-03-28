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

void Game::remove(const int col, const int row, const bool gravity) {
    const int type = grid[col][row];
    grid[col][row] = 0;
    checkNeighbours(col, row, type);
    if (gravity) {
        gravitate();
    }
}

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

void Game::gravitate() {
    for (auto & i : grid) {
        i.erase(std::remove(i.begin(), i.end(), 0),
                      i.end());
    }
}

bool Game::isValid(const int col, const int row) const {
    return !((rowSize <= col) || (col < 0) ||
             (grid[col].size()) <= colSize - (row + 1) || (row < 0));
}
