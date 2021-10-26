#include <iostream>
#include <SFML/Graphics.hpp>
#include"Background.h"
#include"Game.h"
#include"themesong.h"
#include"Menugame.h"
using namespace sf;
int main()
{
    srand((int)time(0));
    RenderWindow window(sf::VideoMode(1080, 720), "Game");

    themesong song;
    Menugame menu;
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
        song.Play();      
        menu.Draw(window);
        window.display();
        window.clear();
    } 
    return 0;
}