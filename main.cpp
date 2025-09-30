#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Skeleton.h"



int main() {
    //--------------------------INITIALIZE---------------------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(1920,1080),"RPG Game",sf::Style::Default,settings);
    window.setFramerateLimit(240);
    //--------------------------INITIALIZE---------------------------------------------------------
    Player player;
    Skeleton skeleton;
    //--------------------------INITIALIZE---------------------------------------------------------
    skeleton.Initialize();
    player.Initialize();
    //--------------------------INITIALIZE---------------------------------------------------------

    //-----------------------------LOAD----------------------------------------------------------------
    player.Load();
    skeleton.Load();
    //-----------------------------LOAD----------------------------------------------------------------

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTimer=clock.restart();
        float deltaTime=deltaTimer.asMilliseconds();

        //------------------------UPDATE---------------------------------------------------------
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type==sf::Event::Closed)
                window.close();
            }

           skeleton.Update(deltaTime);
           player.Update(deltaTime,skeleton);
            //------------------------DRAW---------------------------------------------------------
            window.clear(sf::Color::Black);
            skeleton.Draw(window);
            player.Draw(window);
            window.display();
            //------------------------DRAW---------------------------------------------------------

    }

}
