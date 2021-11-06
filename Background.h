#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
class Background{
public:
	Background();
	~Background();
	void Draw(sf::RenderWindow& window);
	void menubg(sf::RenderWindow& window);
	void scorebg(sf::RenderWindow& window);
	void howtobg(sf::RenderWindow& window);
private:
	sf::RectangleShape bg;
	sf::Vector2f size = { 1080.0f,720.0f };
	sf::Texture bg_texture,menutt,score,howto;
	sf::RectangleShape bgmenu,bgscore,bghowto;
};