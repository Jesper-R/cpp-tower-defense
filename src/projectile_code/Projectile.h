#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../GameObject.h"
#include "../enemy_code/Enemy.h"

class Projectile : public GameObject {
    sf::Vector2f startPos;
    sf::Vector2f currentPos;
    float velocity;
    float damage;
    sf::Vector2f targetPos;
    sf::Vector2f direction;

    //Enemy* target;
    void applyDamage();
public:
    Projectile(float velocity, float damage, const std::string& textureFile, sf::Vector2f startPos, sf::Vector2f targetPos);
    bool checkCollision();
    void update();
    void move();
    void render(sf::RenderWindow& window);


};

#endif //PROJECTILE_H
