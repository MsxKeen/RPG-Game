#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
    sf::RectangleShape rectangleShape;
    sf::Vector2f(direction);
    float speed;
public:


    Bullet();
    ~Bullet();
    void Initialize(const  sf::Vector2f& target,const sf::Vector2f& position,float speed);
    void Load();
    void Update(double deltaTime);
    void Draw(sf::RenderWindow& window);

    inline const sf::FloatRect GetGlobalBounds(){return rectangleShape.getGlobalBounds();}
};
