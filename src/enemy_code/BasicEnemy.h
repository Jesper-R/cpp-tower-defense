//
// Created by Jesper Rudegran on 2024-12-28.
//

#ifndef BASICENEMY_H
#define BASICENEMY_H
#include "Enemy.h"


class BasicEnemy : public Enemy {
    int armor;
public:
    BasicEnemy();
    void move() override;
};



#endif //BASICENEMY_H
