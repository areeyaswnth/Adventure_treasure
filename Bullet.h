#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Bullet
{
public:
	Bullet();
	~Bullet();
	void Draw(sf::RenderWindow& window);
	void update();
	void pos(float pos_x, float pos_y,int Dir);
	void bullet_move();	
	bool state;	
	sf::RectangleShape bullet_body;
private:
	int dir;
	sf::Texture texture;
};

