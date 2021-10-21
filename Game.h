#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include"Monsters.h"
#include"Chest.h"
#include "Player.h"
#include"Bullet.h"
#include "Item.h"
#include "Bullet.h"
class Game
{
public: 
	Game();
	~Game();
	void collision1(int i);
	void collision2(int i);
	void collision3(int i,int j);
	void collision4(int i, int j);
	void collision5();
	void gamedraw(sf::RenderWindow& window,float time);
	void HPupdate();
	void pewbullet();
private:
	int numbullet;
	sf::Clock clock,colorclock,clockitem[3],clockbullet;
	float counttime,colortime,itemtime[3],timebullet;
	Monsters monster[5];
	Chest chest[15];
	Player player;
	Item item[3];
	Bullet bullet[3];
	sf::RectangleShape HP,baseHP;
	float HPsize_x;
	float HPsize_y;
};

