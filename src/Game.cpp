#include "Game.h"
#include <iostream>

#include "map_code/GameMap.h"



void Game::handleEvents()
{
    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            this->window.close();
        }
    }
}

void Game::update()
{
    elapsedTimeSinceLastUpdate += clock.restart();
    //std::cout << "Elapsed time: " << elapsedTimeSinceLastUpdate.asSeconds() << std::endl;

    while (elapsedTimeSinceLastUpdate > timePerFrame)
    {
        elapsedTimeSinceLastUpdate -= timePerFrame;
        //std::cout << "Updated elapsedTimeSinceLastUpdate: " << elapsedTimeSinceLastUpdate.asSeconds() << std::endl;
    }
}

void Game::render()
{
    this->window.clear();
    /*sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Red);
    this->window.draw(shape);
    for (int i = 0; i < GRID_HEIGHT * GRID_WIDTH; ++i) {
        sf::Texture texture;
        if (!texture.loadFromFile("../src/assets/paths/0000/grass.png"))
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        sf::Sprite sprite;
        sprite.setPosition(i % GRID_WIDTH * GRID_SIZE, i / GRID_WIDTH * GRID_SIZE);
        sprite.setTexture(texture);
        this->window.draw(sprite);
    }*/

    gameMap.render(this->window);
    uiManager.renderUI(this->window, player);
    this->window.display();
}

Game::Game()
    :
      timePerFrame(sf::seconds(1.f / 60.f)),
      elapsedTimeSinceLastUpdate(sf::Time::Zero)
{
    gameMap.loadMapFromFile("../src/map.json");
    int width = gameMap.getGridWidth() * GRID_SIZE;
    int height = gameMap.getGridHeight() * GRID_SIZE;
    this->window.create(sf::VideoMode(width, height), "Pixel Defense");
    //gameMap.getMapInfo();
    player.setLives(gameMap.getStartingLives());
    player.setMoney(gameMap.getStartingMoney());
    uiManager.initUI();


}

Game::~Game()
{
    //delete this->balloon;
}

void Game::run()
{
    while (this->window.isOpen())
    {
        //std::cout << "Running loop..." << std::endl;
        handleEvents();
        update();
        render();
    }
}

void Game::renderUI() {

}