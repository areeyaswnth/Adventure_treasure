#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include"Monsters.h"
#include"Chest.h"
#include "Player.h"
#include"Bullet.h"
#include "Item.h"
class Game
{
public: 
	Game();
	~Game();
	void collision1(int i);
	void collision2(int i);
	void collision3(int i);
	void gamedraw(sf::RenderWindow& window,float time);
	void HPupdate();
private:
	sf::Clock clock,colorclock,clockitem[2];
	float counttime,colortime,itemtime[2];
	Monsters monster[5];
	Chest chest[15];
	Player player;
	Item item;
	sf::RectangleShape HP,baseHP;
	float HPsize_x;
	float HPsize_y;
};

