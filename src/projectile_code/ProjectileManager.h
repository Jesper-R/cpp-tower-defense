#ifndef PROJECTILEMANAGER_H
#define PROJECTILEMANAGER_H
#include "Projectile.h"
#include "SFML/Graphics/RenderWindow.hpp"
//#include "../tower_code/Tower.h"
#include <vector>

using namespace std;

class ProjectileManager {
    vector<Projectile*> projectiles; // if not on heap the drawing wont work (white box problem)

public:
    void addProjectile(sf::Vector2i towerPos, sf::Vector2i targetPos, float velocity, float damage, const string& textureFile);

    void update();
    void render(sf::RenderWindow& window);
};



#endif //PROJECTILEMANAGER_H
