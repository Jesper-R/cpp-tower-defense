#include "ProjectileManager.h"
#include "../wave_code/WaveManager.h"
using namespace std;

void ProjectileManager::addProjectile(sf::Vector2i towerPos, sf::Vector2i targetPos, float velocity, float damage,
    const string &textureFile, WaveManager& waveManager) {
    projectiles.push_back(new Projectile(velocity, damage, textureFile, sf::Vector2f(towerPos), sf::Vector2f(targetPos)));
}

void ProjectileManager::removeProjectile(Projectile *projectile) {
    delete projectile;
    projectiles.erase(remove(projectiles.begin(), projectiles.end(), projectile), projectiles.end());
}

void ProjectileManager::update(WaveManager& waveManager) {
    vector<Projectile*> toRemove;

    for (auto& projectile : projectiles) {
        projectile->update(waveManager);
        if (projectile->hasHit()) {
            toRemove.push_back(projectile);
        }
    }

    for (auto& projectile : toRemove) {
        removeProjectile(projectile);
    }
}

void ProjectileManager::render(sf::RenderWindow &window) const {
    for (auto& projectile : projectiles) {
        projectile->render(window);
    }
}
