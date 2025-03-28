#ifndef GAME_H
#define GAME_H
#include <vector>
using namespace std;

class Game {
   public:
    vector<vector<int> > grid;
    explicit Game(const vector<vector<int> > &grid);
    unsigned long rowSize;
    unsigned long colSize;
    string stringify() const;
    void remove(int col, int row, bool gravity);

   private:
    void checkNeighbours(int col, int row, int type);
    void gravitate();
    bool isValid(int col, int row) const;
};

#endif
