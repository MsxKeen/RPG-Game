#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    //--------------------------INITIALIZE---------------------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(1920,1080),"RPG Game",sf::Style::Default,settings);

    //--------------------------INITIALIZE---------------------------------------------------------

    //--------------------------LOAD---------------------------------------------------------

    //--------------------------SKELETON---------------------------------------------------------
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    if(enemyTexture.loadFromFile("C:/Users/mertc/CLionProjects/RPG-Game/Assets/Skeleton/Textures/SpriteSheet.png")){
        std::cout<<"Player Texture Loaded"<<std::endl;
        enemySprite.setTexture(enemyTexture);
        enemySprite.setPosition(sf::Vector2f(400,100));

        //X, Y, Width, Height
        int XIndex=0;
        int YIndex=2;
        enemySprite.setTextureRect(sf::IntRect(XIndex*64,YIndex*64,64,64));
        enemySprite.setScale(sf::Vector2f(3,3));

    } else {std::cout<<"Player Texture Error"<<std::endl;}
    //--------------------------SKELETON---------------------------------------------------------
    //--------------------------PLAYER---------------------------------------------------------

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if(playerTexture.loadFromFile("C:/Users/mertc/CLionProjects/RPG-Game/Assets/Player/Textures/SpriteSheet.png")) {
        std::cout<<"Player Texture Loaded"<<std::endl;
        playerSprite.setTexture(playerTexture);

        //X, Y, Width, Height
        int XIndex=0;
        int YIndex=00;
        playerSprite.setTextureRect(sf::IntRect(XIndex*64,YIndex*64,64,64));
        playerSprite.setScale(sf::Vector2f(3,3));
    }
    else {std::cout<<"Player Texture Error"<<std::endl;}
    //--------------------------PLAYER---------------------------------------------------------


    //--------------------------LOAD---------------------------------------------------------

    //main game loop
    while (window.isOpen()) {
        //------------------------UPDATE---------------------------------------------------------
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type==sf::Event::Closed)
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
                    playerSprite.setPosition(position+ sf::Vector2f(1 ,0));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                playerSprite.setPosition(position - sf::Vector2f(1,0));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                playerSprite.setPosition(position + sf::Vector2f(0,1));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                playerSprite.setPosition(position - sf::Vector2f(0,1));//or (position + sf::Vector2f(0,-10))
            }


            //------------------------UPDATE---------------------------------------------------------

            //------------------------DRAW---------------------------------------------------------
            window.clear(sf::Color::Black);
            window.draw(playerSprite);
            window.draw(enemySprite);
            window.display();
            //------------------------DRAW---------------------------------------------------------

    }

}