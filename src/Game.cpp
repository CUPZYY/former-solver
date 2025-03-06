#include <iostream>
using namespace std;

class Game {
   public:
    vector<vector<int> > grid;
    int ySize;
    int xSize;

    Game(vector<vector<int> > grid) {
        this->grid = grid;
        ySize = grid.size();
        xSize = grid[0].size();
    };

    string stringify() {
        string res = "";
        for (int x = 0; x < xSize; x++) {
            for (int y = 0; y < grid.size(); y++) {
                if (xSize - grid[y].size() <= x) {
                    res +=
                        to_string(grid[y][x - (xSize - grid[y].size())]) + " ";
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
