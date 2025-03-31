#ifndef MCTS_H
#define MCTS_H
#include <Game.h>
#include <random>

class MCTS {
   public:
    Game game;
    explicit MCTS(Game& game);
   private:
    Game randomMove();
};

#endif  // MCTS_H
