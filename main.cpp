#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    //--------------------------INITIALIZE---------------------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(800,600),"RPG Game",sf::Style::Default,settings);

    //--------------------------INITIALIZE---------------------------------------------------------

    //--------------------------LOAD---------------------------------------------------------

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if(playerTexture.loadFromFile("C:/Users/mertc/CLionProjects/RPG-Game/Assets/Player/Textures/SpriteSheet.png")) {
        std::cout<<"Player Texture Loaded"<<std::endl;
        playerSprite.setTexture(playerTexture);

        //X, Y, Width, Height
        int XIndex=8;
        int YIndex=3;
        playerSprite.setTextureRect(sf::IntRect(XIndex*64,YIndex*64,64,64));
        playerSprite.setScale(sf::Vector2f(3,3));
    }
    else {std::cout<<"Player Texture Error"<<std::endl;}

    //--------------------------LOAD---------------------------------------------------------

    //main game loop
    while (window.isOpen()) {
        //------------------------UPDATE---------------------------------------------------------
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type==sf::Event::Closed) {
                window.close();
            }

            // if(event.type== sf::Event::KeyPressed) {
            //     if(event.key.code==sf::Keyboard::D){
            //         sf::Vector2f position=playerSprite.getPosition();
            //         playerSprite.setPosition(position+ sf::Vector2f(10 ,0));
            //     }
            // } //not good
            sf::Vector2f position=playerSprite.getPosition();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    playerSprite.setPosition(position+ sf::Vector2f(10 ,0));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                playerSprite.setPosition(position - sf::Vector2f(10,0));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                playerSprite.setPosition(position + sf::Vector2f(0,10));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                playerSprite.setPosition(position - sf::Vector2f(0,10));//or (position + sf::Vector2f(0,-10))
            }

            //------------------------UPDATE---------------------------------------------------------

            //------------------------DRAW---------------------------------------------------------
            window.clear(sf::Color::Black);
            window.draw(playerSprite);
            window.display();
            //------------------------DRAW---------------------------------------------------------
        }
    }

}