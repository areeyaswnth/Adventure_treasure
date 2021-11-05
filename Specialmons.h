#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Specialmons
{
public:
	Specialmons();
	~Specialmons();
	void update();
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape body;
	int HP;
	bool state;
	int level;
	bool monstate;

private:
	sf::Texture texture;
	float speed;
	int randtype;
	float pos_x;
	float pos_y;
	int dirx, diry;
	int step;
};

