#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include"Monsters.h"
#include"Chest.h"
#include "Player.h"
#include"Bullet.h"
class Game
{
public: 
	Game();
	~Game();
	void collision1(int i);
	void collision2(int i);
	void gamedraw(sf::RenderWindow& window,float time);
private:
	sf::Clock clock;
	float counttime;
	Monsters monster[5];
	Chest chest[15];
	Player player;
};

