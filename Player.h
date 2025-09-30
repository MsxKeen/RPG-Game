#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player {
private:
    sf::Texture Texture;
    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed=0.5f;
public:
    sf::Sprite  Sprite;
public:
    void Initialize();
    void Load();
    void Update(Skeleton& skeleton);
    void Draw(sf::RenderWindow& window);
};



