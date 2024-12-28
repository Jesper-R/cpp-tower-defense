//
// Created by Jesper Rudegran on 2024-12-28.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "../GameObject.h";

class Enemy : public GameObject {
    float health;
    float speed;
    int value;
public:
    Enemy(float health, float speed, int value, const std::string& textureFile);
    void takeDamage(float damage);
    void die();
    virtual void move() = 0;
};



#endif //ENEMY_H
