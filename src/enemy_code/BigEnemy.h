//
// Created by Jesper Rudegran on 2024-12-28.
//

#ifndef BIGENEMY_H
#define BIGENEMY_H
#include "Enemy.h"


class BigEnemy : public Enemy {
    int armor;
public:
    BigEnemy();
    void move() override;
};



#endif //BIGENEMY_H
