//
// Created by Jesper Rudegran on 2024-12-28.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "../GameObject.h";
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class GameMap;

class Enemy : public GameObject {
    float health;
    float speed;
    int value;
    int damage;
    int currentTargetIndex = 0;
    sf::Vector2i startPos;
    sf::Vector2i currentPos;
    vector<sf::Vector2i> turnLocs;
    vector<sf::Vector2i> pathFindingData;
    sf::Vector2i endPos;
    bool dead = false;
    bool reachedEnd = false;
public:
    Enemy(float health, float speed, int value, const std::string& textureFile, int damage);
    virtual void takeDamage(float damage, int armor=0);
    void die();
    virtual void update(float deltaTime);
    virtual void render(sf::RenderWindow& window);
    virtual void move();
    //void setPath(const sf::Vector2i& start, const sf::Vector2i& end);
    void setPath(GameMap& map);
    vector<sf::Vector2i> getPathFindingData() const { return pathFindingData; }
    void setPos(sf::Vector2f pos) { currentPos = sf::Vector2i(pos); }
    sf::Vector2i getStartPos() const { return startPos; }
    sf::Vector2i getCurrentPos() const { return currentPos; }
    sf::Vector2i getEndPos() const { return endPos; }
    void setCurrentPos(sf::Vector2i pos) { currentPos = pos; setPosition(sf::Vector2f(pos)); }
    float getSpeed() const { return speed; }
    bool isDead() const { return dead; }
    bool hasReachedEnd() const { return reachedEnd; }
    void setReachedEnd(bool reachedEnd) { this->reachedEnd = reachedEnd; }
    int getDamage() const { return damage; }
    int getValue() const { return value; }
};



#endif //ENEMY_H