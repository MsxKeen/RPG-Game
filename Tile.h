#pragma once
#include <SFML/Graphics.hpp>

struct Tile {
    int id=-1;
   // sf::IntRect rect;//4 floats x,y,w,h instead of using intrect we use vector2f because we dont need w and h its waste of memory
    sf::Vector2i position;
};
