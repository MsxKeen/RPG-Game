#pragma once
#include <SFML/Graphics.hpp>

class FrameRates {
    sf::Text frameRateText;
    sf::Font font;

    float timer;

public:
    FrameRates();//constructors have to be public
    ~FrameRates();//destructors have to be public

    void Load();
    void Initialize();
    void Update(double deltaTime);
    void Draw(sf::RenderWindow& window);
};



