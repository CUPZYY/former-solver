#include <Game.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

Game::Game(const vector<vector<int> > &grid) {
    this->grid = grid;
    for (int i = 0; i < grid.size(); i++) {
        nonEmptyColumns.push_back(i);
    }
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
    const int actualRow = convertRow(row, col);
    const int type = grid[col][actualRow];
    grid[col][actualRow] = 0;
    checkNeighbours(col, row, type);
    if (isDirectCall) {
        for (int col_i = nonEmptyColumns.size() - 1; col_i >= 0; col_i--) {
            gravitate(grid[nonEmptyColumns[col_i]]);
            if (grid[nonEmptyColumns[col_i]].empty()) {
                nonEmptyColumns.erase(nonEmptyColumns.begin() + col_i);
            }
        }
    }
}

bool Game::isFinished() const { return nonEmptyColumns.empty(); }

void Game::checkNeighbours(const int col, const int row, const int type) {
    const int actualRow = convertRow(row, col);
    const int leftRow = convertRow(row, col - 1);
    const int rightRow = convertRow(row, col + 1);
    if (isValid(col, row - 1) && (grid[col][actualRow + 1] == type)) {
        remove(col, row - 1, false);
    }
    if (isValid(col, row + 1) && (grid[col][actualRow - 1] == type)) {
        remove(col, row + 1, false);
    }
    if (isValid(col + 1, row) && (grid[col + 1][rightRow] == type)) {
        remove(col + 1, row, false);
    }
    if (isValid(col - 1, row) && (grid[col - 1][leftRow] == type)) {
        remove(col - 1, row, false);
    }
}

void Game::gravitate(vector<int> &col) {
    col.erase(std::remove(col.begin(), col.end(), 0), col.end());
}

bool Game::isValid(const int col, const int row) const {
    return !(!binary_search(nonEmptyColumns.begin(), nonEmptyColumns.end(), col) ||
             grid[col].size() <= row || row < 0);
}

int Game::convertRow(const int row, const int col) const {
    return grid[col].size() - row - 1;
}
