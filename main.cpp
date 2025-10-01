#include <iostream>
#include <SFML/Graphics.hpp>
#include "FrameRates.h"
#include "Player.h"
#include "Skeleton.h"



int main() {
    //--------------------------INITIALIZE---------------------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(1920,1080),"RPG Game",sf::Style::Default,settings);
    window.setFramerateLimit(120);
    //--------------------------INITIALIZE---------------------------------------------------------
    FrameRates frames;
    Player player;
    Skeleton skeleton;
    //--------------------------INITIALIZE---------------------------------------------------------
    frames.Initialize();
    skeleton.Initialize();
    player.Initialize();
    //--------------------------INITIALIZE---------------------------------------------------------

    //-----------------------------LOAD----------------------------------------------------------------
    frames.Load();
    player.Load();
    skeleton.Load();
    //-----------------------------LOAD----------------------------------------------------------------

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTimer=clock.restart();
        double deltaTime=deltaTimer.asMicroseconds()/1000.0;

        //------------------------UPDATE---------------------------------------------------------
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type==sf::Event::Closed)
                window.close();
            }

           frames.Update(deltaTime);
           skeleton.Update(deltaTime);
           player.Update(deltaTime,skeleton);

            //------------------------DRAW---------------------------------------------------------
            window.clear(sf::Color::Black);
            skeleton.Draw(window);
            player.Draw(window);
            frames.Draw(window);
            window.display();
            //------------------------DRAW---------------------------------------------------------

    }

}
