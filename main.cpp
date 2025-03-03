#include <iostream>
using namespace std;

/*
    1: Blue
    2: Green
    3: Orange
    4: Pink
*/

class Game {
   public:
    vector<vector<int> > grid = {
        {1, 2, 1, 2, 4, 1, 3, 3, 1}, {2, 3, 3, 1, 3, 1, 1, 3, 2},
        {1, 4, 4, 1, 4, 4, 2, 3, 1}, {4, 3, 2, 3, 4, 3, 1, 4, 1},
        {3, 4, 3, 3, 2, 3, 2, 3, 4}, {3, 2, 4, 4, 2, 3, 4, 2, 3},
        {4, 2, 3, 1, 3, 2, 4, 1, 2}};

    const int ySize = grid.size();
    const int xSize = grid[0].size();

    string stringify() {
        string res = "";
        for (int row = 0; row < xSize; row++) {
            for (int col = 0; col < grid.size(); col++) {
                if (xSize - grid[col].size() <= row) {
                    res +=
                        to_string(grid[col][row - (xSize - grid[col].size())]) +
                        " ";
                } else {
                    res += "  ";
                }
            }
            res += "\n";
        }
        return res;
    }

    void remove(int x, int y, bool root = true) {
        int type = grid[x][y];
        grid[x][y] = 0;
        checkNeighbours(x, y, type);
        if (root) {
            gravitate();
        }
    }

   private:
    void checkNeighbours(int x, int y, int type) {
        if (grid[x][y + 1] == type) remove(x, y + 1, false);
        if (grid[x][y - 1] == type) remove(x, y - 1, false);
        if (grid[x + 1][y] == type) remove(x + 1, y, false);
        if (grid[x - 1][y] == type) remove(x - 1, y, false);
    }

    void gravitate() {
        for (int i = 0; i < grid.size(); i++) {
            grid[i].erase(std::remove(grid[i].begin(), grid[i].end(), 0),
                          grid[i].end());
        }
    }
};

Game game;

int main() { cout << game.stringify(); };
