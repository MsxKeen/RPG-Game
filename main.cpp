#include <SFML/Graphics.hpp>

int main() {
    //--------------------------INITIALIZE---------------------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(800,600),"RPG Game",sf::Style::Default,settings);
    sf::CircleShape shape(50.0f,6);
    shape.setFillColor(sf::Color(100,250,50));
    shape.setPosition(sf::Vector2f(100,100));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Yellow);


    sf::RectangleShape rectangle(sf::Vector2f(120.f,50.f));
    rectangle.setFillColor(sf::Color::Yellow);
    rectangle.setPosition(sf::Vector2f(60,60));
    rectangle.setOutlineThickness(10);
    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setOrigin(rectangle.getSize()/2.f);
    rectangle.setRotation(45);

    sf::RectangleShape line(sf::Vector2f(300.f,3.f));
    line.setPosition(sf::Vector2f(300,100));
    line.setFillColor(sf::Color::Blue);
    line.rotate(45.f);


    //--------------------------INITIALIZE---------------------------------------------------------

    //main game loop
    while (window.isOpen()) {
        //------------------------UPDATE---------------------------------------------------------
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type==sf::Event::Closed) {
                window.close();
            }
            //------------------------UPDATE---------------------------------------------------------

            //------------------------DRAW---------------------------------------------------------
            window.clear(sf::Color::Black);
            window.draw(shape);
            window.draw(rectangle);
            window.draw(line);
            window.display();
            //------------------------DRAW---------------------------------------------------------
        }
    }

}