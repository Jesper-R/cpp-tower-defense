#pragma once
#include <SFML/Graphics.hpp>

#include "GameMap.h"

class Game
{
private:
    static const int WIDTH = 1280;
    static const int HEIGHT = 720;
    static const int GRID_SIZE = 64;
    static const int GRID_WIDTH = WIDTH / GRID_SIZE;
    static const int GRID_HEIGHT = HEIGHT / GRID_SIZE;
    GameMap map;
private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time timePerFrame;
    sf::Time elapsedTimeSinceLastUpdate;

    void handleEvents();
    void update();
    void render();
public:
    Game();
    ~Game();
    void run();
};
