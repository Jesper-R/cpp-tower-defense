#ifndef PROJECTILEMANAGER_H
#define PROJECTILEMANAGER_H

#include "Projectile.h"
#include "../wave_code/WaveManager.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include <vector>
using namespace std;

class ProjectileManager {
    vector<Projectile*> projectiles; // if not on heap the drawing wont work (white box problem
public:
    ProjectileManager(){};
    ~ProjectileManager();
    void addProjectile(sf::Vector2i towerPos, sf::Vector2i targetPos, float velocity, float damage, const string& textureFile);
    void removeProjectile(Projectile* projectile);
    void update(WaveManager& waveManager, sf::RenderWindow& window);
    void render(sf::RenderWindow& window) const;
};

#endif //PROJECTILEMANAGER_H
