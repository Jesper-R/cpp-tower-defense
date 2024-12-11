#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:
    static const int WIDTH = 900;
    static const int HEIGHT = 600;
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
