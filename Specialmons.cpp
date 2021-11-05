#include "Specialmons.h"
#include<time.h>
float randrangemonster(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return float(n);
}
Specialmons::Specialmons()
{
	monstate = false;
	HP = 100;
	texture.loadFromFile("graphics/monster1.png");
	body.setTextureRect(sf::IntRect(0, 0, 23.0f, 26.0f));
	body.setTexture(&texture);
	body.setSize(sf::Vector2f(55.2f, 62.4f));
	body.setPosition(randrangemonster(55, 1025), randrangemonster(200, 680));
	pos_x = body.getPosition().x;
	pos_y = body.getPosition().y;
}

Specialmons::~Specialmons()
{
}

void Specialmons::update()
{
}

void Specialmons::Draw(sf::RenderWindow& window)
{
	if (HP > 0) {
		state = true;
		window.draw(body);
	}
}
