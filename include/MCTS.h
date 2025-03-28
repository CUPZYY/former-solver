#ifndef MCTS_H
#define MCTS_H
#include <Game.h>

class MCTS {
   public:
    Game game;
    explicit MCTS(Game& game);
};

#endif  // MCTS_H
