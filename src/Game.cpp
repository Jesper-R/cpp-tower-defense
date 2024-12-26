#include "Game.h"
#include <iostream>

#include "GameMap.h"



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

    map.render(this->window);



    this->window.display();
}

Game::Game()
    :
      timePerFrame(sf::seconds(1.f / 60.f)),
      elapsedTimeSinceLastUpdate(sf::Time::Zero)
{
    map.loadMapFromFile("../src/map.json");
    int width = map.getWidth() * GRID_SIZE;
    int height = map.getHeight() * GRID_SIZE;
    this->window.create(sf::VideoMode(width, height), "Pixel Defense");

    //map.loadMapFromFile("map.json");
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
