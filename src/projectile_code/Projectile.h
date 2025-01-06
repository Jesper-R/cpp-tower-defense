#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../GameObject.h"
#include "../wave_code/WaveManager.h"

class ProjectileManager;

class Projectile : public GameObject {
    sf::Vector2f startPos;
    sf::Vector2f currentPos;
    sf::Vector2f targetPos;
    sf::Vector2f direction;
    float velocity;
    float damage;
    bool hit = false;
    WaveManager* waveManager;
    ProjectileManager* projectileManager;
public:
    Projectile(float velocity, float damage, const std::string& textureFile, sf::Vector2f startPos, sf::Vector2f targetPos, WaveManager* waveManager, ProjectileManager* projectileManager);
    void checkCollision(WaveManager* waveManager);
    void update();
    void move();
    void render(sf::RenderWindow& window);
    bool hasHit() const;
};

#endif //PROJECTILE_H
