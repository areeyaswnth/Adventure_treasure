#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
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
	void gamedraw(sf::RenderWindow& window,float time);
	bool state;
private:	
	sf::SoundBuffer buffer[5];
	sf::Sound sound[5];
	void collision1(int i);
	void collision2(int i);
	void collision3(int i,int j);
	void collision4(int i, int j);		
	void HPupdate();
	void pewbullet();
	void collision5(int i);
	int numbullet;
	sf::Clock clock,colorclock,clockitem[2],clockbullet,skillclock[2];
	float counttime,colortime,itemtime[2],timebullet,skilltime[2];
	Monsters monster[5];
	Chest chest[15];
	Player player;
	Item item[3];
	Bullet bullet[3];
	sf::RectangleShape HP,baseHP;
	float HPsize_x;
	float HPsize_y;
	int skills[2];
};

