#pragma once
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "WaveManager.h"
#include "map_code/GameMap.h"

class Game
{
private:
    static const int WIDTH = 1280;
    static const int HEIGHT = 720;
    static const int GRID_SIZE = 64;
    static const int GRID_WIDTH = WIDTH / GRID_SIZE;
    static const int GRID_HEIGHT = HEIGHT / GRID_SIZE;
    GameMap gameMap;
    WaveManager waveManager;
    Player player;
private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time timePerFrame;
    sf::Time elapsedTimeSinceLastUpdate;
    sf::Font font;
    sf::Text livesText;
    sf::Text moneyText;

    void handleEvents();
    void update();
    void render();
    void renderUI();
public:
    Game();
    ~Game();
    void run();
};
