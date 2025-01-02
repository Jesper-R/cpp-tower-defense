#include "ProjectileManager.h"

void ProjectileManager::addProjectile(sf::Vector2i towerPos, sf::Vector2i targetPos, float velocity, float damage,
    const string &textureFile, WaveManager* waveManager) {
    projectiles.push_back(new Projectile(velocity, damage, textureFile, sf::Vector2f(towerPos), sf::Vector2f(targetPos), waveManager, this));
}

void ProjectileManager::removeProjectile(Projectile *projectile) {
    projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), projectile), projectiles.end());
}

void ProjectileManager::update() {
    for (auto& projectile : projectiles) {
        projectile->update();
    }
}

void ProjectileManager::render(sf::RenderWindow &window) {
    for (auto& projectile : projectiles) {
        projectile->render(window);
    }
}
