#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Specialmons.h"
#include"Monsters.h"
#include"Chest.h"
#include "Player.h"
#include"Bullet.h"
#include "Item.h"
#include "Bullet.h"
#include<string.h>


class Game
{
public: 
	Game();
	~Game();
	void gamedraw(sf::RenderWindow& window,float time);
	bool state;	
	bool over();
	void reset();	
	std::string username;
	int scorep;	
	int level;	
private:	
	int spe;

	int chest_count;
	sf::Event event;
	sf::SoundBuffer buffer[7];
	sf::Sound sound[7];
	sf::Font font;
	void level_update();
	void scoreupdate();
	void collision1(int i);
	void collision2(int i);
	void collision3(int i,int j);
	void collision4(int i, int j);	
	void HPupdate();
	void pewbullet();
	void collision5(int i);	
	void collision6(int i, int j);
	void collision7(int i);
	void leveluptext();
	int numbullet;
	sf::Clock clock,colorclock,clockitem[2],clockbullet,skillclock[2];
	float counttime,colortime,itemtime[2],timebullet,skilltime[2];
	Monsters monster[5];
	Chest chest[15];
	Player player;
	Item item[3];
	Bullet bullet[3];
	Specialmons spemons[2];
	sf::Text textscore,score,gameover,Level;
	sf::RectangleShape HP,baseHP;
	float HPsize_x;
	float HPsize_y;
	int skills[2];
	int countover;
	int monstermax, chestmax;
};

