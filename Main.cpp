#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define __STD_WANT_LIB_EXIT__ 1
#include <iostream>
#include <SFML/Graphics.hpp>
#include"Background.h"
#include"Game.h"
#include"themesong.h"
#include"Menugame.h"
#include<string.h>
#include<vector>
#include<algorithm>
#include <windows.h>

void draw_username();
using namespace sf;    
using namespace std;
vector<char> username;    
string user_name = "";    
Background bg;
RenderWindow window(sf::VideoMode(1080, 720), "Game");
    Menugame menu;  
int main()
{

    bool namestate =false;
    srand((int)time(0));
    themesong song;
    while (window.isOpen())
    {
        Event event;
        if (!menu.menu_state && !menu.game_state && !menu.namestate && !menu.highscore_state && !menu.howto_state) {
            namestate = true;
        }
        while (window.pollEvent(event))
        {
           
           if (namestate) {
                if (event.type == sf::Event::TextEntered) {
                username.push_back(event.text.unicode);
            }

            if (!username.empty() && username.back() == 8)
            {
                username.pop_back();
                if (!username.empty())
                    username.pop_back();

            }

            if (username.size() != 1 && !username.empty() && username.back() == 13)
            {
                username.pop_back();
            }
            if (!username.empty() && !((username.back() >= 'a' && username.back() <= 'z') || (username.back() >= 'A' && username.back() <= 'Z') || (username.back() >= '0' && username.back() <= '9') || username.back() == '_'))
            {
                username.pop_back();
            }
            if (username.size() > 15)
            {
                username.pop_back();
            }            
            if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                menu.clicksound.play();
                menu.getname(user_name);
                menu.namestate = true;
                menu.game_state = true;
                namestate = false;
            }

            }
         if (Keyboard::isKeyPressed(Keyboard::Escape) || (event.type == sf::Event::Closed)) {
                window.close();
             }              

        }
        if (namestate) {
            bg.Draw(window);
            draw_username();
        }
        if (!namestate) {

            menu.Draw(window);
        }            
            song.Play();
            window.display();
            window.clear();
    }

    return 0;
}

void draw_username()
{
    user_name = "";
    sf::Text US_name;
    sf::Font font;
    font.loadFromFile("font/8Bit.ttf");
    US_name.setFont(font);
    for (int i = 0; i < username.size(); i++)
    {
        user_name += username[i];
    }
    US_name.setCharacterSize(55);
    if (username.empty())
    {
        US_name.setFillColor(sf::Color(255, 255, 255, 100));
        US_name.setString("ENTER YOUR NAME");
    }
    else
    {
        //menu.clicksound.play();
        US_name.setString(user_name);
        US_name.setFillColor(sf::Color::White);
    }
    US_name.setPosition(540-(US_name.getGlobalBounds().width/2), 330);
    window.draw(US_name);
}
