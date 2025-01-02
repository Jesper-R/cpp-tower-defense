#ifndef PROJECTILE_H
#define PROJECTILE_H

//#include "ProjectileManager.h"
#include "../GameObject.h"
#include "../enemy_code/Enemy.h"
#include "../wave_code/WaveManager.h"

class ProjectileManager;

class Projectile : public GameObject {
    sf::Vector2f startPos;
    sf::Vector2f currentPos;
    float velocity;
    bool hit = false;
    float damage;
    sf::Vector2f targetPos;
    sf::Vector2f direction;
    WaveManager* waveManager;
    ProjectileManager* projectileManager;

    //Enemy* target;
    void applyDamage();
public:
    Projectile(float velocity, float damage, const std::string& textureFile, sf::Vector2f startPos, sf::Vector2f targetPos, WaveManager* waveManager, ProjectileManager* projectileManager);
    void checkCollision(WaveManager* waveManager);
    void update();
    void move();
    void render(sf::RenderWindow& window);
    bool hasHit() const { return hit; }

};

#endif //PROJECTILE_H
