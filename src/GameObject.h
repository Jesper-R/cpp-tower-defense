//
// Created by Jesper Rudegran on 2024-12-28.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"


class GameObject {
    sf::Vector2f position = sf::Vector2f(0, 0);
    sf::Sprite sprite;
    sf::Texture texture;
public:
    GameObject(std::string textureFile);
    void update();
    void render();
    void setTexture(const std::string& textureFile);
};



#endif //GAMEOBJECT_H
