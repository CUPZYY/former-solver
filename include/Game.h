#ifndef GAME_H
#define GAME_H
#include <vector>
using namespace std;

class Game {
   public:
    vector<vector<int> > grid;
    explicit Game(const vector<vector<int> > &grid);
    int rowSize;
    int colSize;
    string stringify();
    void remove(int col, int row, bool gravity);

   private:
    void checkNeighbours(int col, int row, int type);
    void gravitate();
    bool isValid(int col, int row);
};

#endif
