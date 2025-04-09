#ifndef MCTS_H
#define MCTS_H
#include <Game.h>
#include <random>

class MCTS {
public:
    Game game;

    explicit MCTS(Game &game);

    struct Move {
        int col;
        int row;
        double moves;
    };

    vector<MCTS::Move> solve(int iterations);

    Move findNextMove(int iterations);

    double simulate(const Game &gameRollout, int iterations);

private:
    random_device rd;

    Game randomMove(Game &gameRollout);
};

#endif  // MCTS_H
