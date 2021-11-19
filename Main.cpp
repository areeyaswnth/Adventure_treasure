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
#include<sstream>
void draw_username();
using namespace sf;    
using namespace std;
vector<char> username;    
string player_name = "";    
Background bg;
RenderWindow window(sf::VideoMode(1080, 720), "Game");
Menugame menu;  
Texture nameboardtexture;
Sprite nameboard;
int main()
{
    nameboardtexture.loadFromFile("graphics/name.png");
    nameboard.setTexture(nameboardtexture);
    nameboard.setScale(5,5);
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
            if (!username.empty() && !((username.back() >= 'A' && username.back() <= 'Z') || (username.back() >= 'a' && username.back() <= 'z') || (username.back() >= '0' && username.back() <= '9') || username.back() == '_'))
            {
                username.pop_back();
            }
            if (username.size() > 15)
            {
                username.pop_back();
            }            
            if (Keyboard::isKeyPressed(Keyboard::Enter)&& username.size()!=0) {
                menu.clicksound.play();
                menu.getname(player_name);
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
            bg.menubg(window);
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
    std::stringstream ss;
    player_name = "";
    Text p_name;
    Font font;
    font.loadFromFile("font/8Bit.ttf");    
    Text enter("Player name",font,80);
    enter.setFillColor(sf::Color(255, 255, 255, 100));
    enter.setPosition(340, 150);
    p_name.setFont(font);
    for (int i = 0; i < username.size(); i++)
    {
        player_name += username[i];
    }
    p_name.setCharacterSize(55);
    if (username.empty())
    {      
        p_name.setFillColor(sf::Color(255, 255, 255, 180));
        p_name.setString("_");
    }
    else
    {       
        ss << player_name<<"_";
        std::string str = ss.str();
        p_name.setString(str);
        p_name.setFillColor(sf::Color::White);
    }
    p_name.setPosition(540-(p_name.getGlobalBounds().width/2), 330);
    nameboard.setPosition(540 - (nameboard.getGlobalBounds().width / 2), 260);
    window.draw(nameboard);
    window.draw(p_name);
    window.draw(enter);

}
