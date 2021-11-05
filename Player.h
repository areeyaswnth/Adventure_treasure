#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
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
	float scorebonus;
	int dir_bullet;	
	int animationFrame;
private:
	sf::Clock pClock;
	double pTime;
	sf::Texture bullettexture;
	sf::Texture player_texture;
	unsigned int row;
	float speed;
	bool faceRight;
	int body_xsize;
	int body_ysize;

	int max_HP=100;


};