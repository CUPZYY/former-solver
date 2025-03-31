#ifndef MCTS_H
#define MCTS_H
#include <Game.h>
#include <random>

class MCTS {
   public:
    Game game;
    explicit MCTS(Game& game);
    double simulate(const Game& gameRollout, int iterations);
   private:
    random_device rd;
    Game randomMove(Game &gameRollout);
};

#endif  // MCTS_H
