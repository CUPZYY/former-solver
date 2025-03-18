#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Game {
   public:
    vector<vector<int> > grid;
    int rowSize;
    int colSize;

    Game(vector<vector<int> > grid) {
        this->grid = grid;
        rowSize = grid.size();
        colSize = grid[0].size();
    };

    string stringify() {
        string res = "";
        for (int col = 0; col < colSize; col++) {
            for (int row = 0; row < rowSize; row++) {
                if (colSize - grid[row].size() <= col) {
                    res += to_string(
                               grid[row][col - (colSize - grid[row].size())]) +
                           " ";
                } else {
                    res += "  ";
                }
            }
            res += "\n";
        }
        return res;
    }

    void remove(int col, int row, bool gravity = true) {
        int type = grid[col][row];
        grid[col][row] = 0;
        checkNeighbours(col, row, type);
        if (gravity) {
            gravitate();
        }
    }

   private:
    void checkNeighbours(int col, int row, int type) {
        if (isValid(col, row + 1) && (grid[col][row + 1] == type))
            remove(col, row + 1, false);
        if (isValid(col, row - 1) && (grid[col][row - 1] == type))
            remove(col, row - 1, false);
        if (isValid(col + 1, row) && (grid[col + 1][row] == type))
            remove(col + 1, row, false);
        if (isValid(col - 1, row) && (grid[col - 1][row] == type))
            remove(col - 1, row, false);
    }

    void gravitate() {
        for (int i = 0; i < grid.size(); i++) {
            grid[i].erase(std::remove(grid[i].begin(), grid[i].end(), 0),
                          grid[i].end());
        }
    }

    bool isValid(int col, int row) {
        return !((rowSize <= col) || (col < 0) ||
                 (grid[col].size()) <= colSize - (row + 1) || (row < 0));
    }
};