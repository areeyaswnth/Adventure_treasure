#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include"Bullet.h"
class Player {
public:
	Player();
	~Player();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window, float deltatime);
	sf::FloatRect Collision();
	sf::RectangleShape body;	
	int HP;	
	size_t score;	
	Bullet bullet;
private:
	sf::Texture bullettexture;
	sf::Texture player_texture;
	unsigned int row;
	float speed;
	bool faceRight;
	int body_xsize;
	int body_ysize;
	int animationFrame;
	int max_HP=100;
	int dir_bullet;
	int numbullet;
	sf::Clock time;
	float timebullet;
};