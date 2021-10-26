#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include"Game.h"
#include"Background.h"
class Menugame
{
public: 
	Menugame();
	~Menugame();
	void update(sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void mouseclick(sf::RenderWindow& window);
private:
	bool menu_state, game_state, howto_state, highscore_state;
	sf::Text play,Highscore,Howto,Name,ary;
	sf::Font font,misname;
	float deltaTime = 0.0f;
	Background backgrounds;
	sf::Clock clock[2];
	Game game;
};

