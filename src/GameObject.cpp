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
    this->sprite.setTexture(this->texture);
}

void GameObject::update() {
}

void GameObject::render() {
}
