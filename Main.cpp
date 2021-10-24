#include <iostream>
#include <SFML/Graphics.hpp>
#include"Background.h"
#include"Game.h"
#include"themesong.h"
using namespace sf;
int main()
{
    srand((int)time(0));
    RenderWindow window(sf::VideoMode(1080, 720), "Game");
    float deltaTime = 0.0f;
    Background backgrounds;
    Clock clock[2];
    Game game;
    themesong song;
   // game.state = true;
    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape)||(event.type==sf::Event::Closed)) {
                window.close();
            } 
        }
        if (game.state) { 
            song.Play();
            deltaTime = clock[0].getElapsedTime().asMilliseconds();
            if (deltaTime > 15) {
                clock[0].restart();
              }               
            backgrounds.Draw(window);
            game.gamedraw(window,deltaTime);          

        }
        else
        {

        }

        window.display();
        window.clear();

    }
    
    return 0;
}