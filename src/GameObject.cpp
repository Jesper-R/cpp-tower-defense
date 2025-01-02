//
// Created by Jesper Rudegran on 2024-12-28.
//

#include "GameObject.h"

#include <iostream>
#include <string>

GameObject::GameObject(std::string textureFile) {
    if (!this->texture.loadFromFile(textureFile)) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    std::cout << "loaded texture" << textureFile << std::endl;
    this->sprite.setTexture(this->texture);
}

void GameObject::update() {
}

void GameObject::render() {
}

void GameObject::setTexture(const std::string &textureFile) {
}

sf::Sprite* GameObject::getSprite() {
    return &sprite;
}

sf::Texture GameObject::getTexture() const {
}

sf::Vector2f GameObject::getPosition() const {
    return this->position;
}



void GameObject::setPosition(const sf::Vector2f &position) {
    this->position = position;
}
