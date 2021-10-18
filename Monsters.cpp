#include "Monsters.h"
#include<time.h>
using namespace std;

float randrangemonster(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return float(n);
}

Monsters::Monsters()
{
	HP = 100;
	texture.loadFromFile("graphics/monster1.png");
	body.setTextureRect(sf::IntRect(0, 0, 23.0f, 26.0f));
	body.setTexture(&texture);
	body.setSize(sf::Vector2f(55.2f, 62.4f));
	body.setPosition(randrangemonster(55, 1025), randrangemonster(200,680));
	pos_x = body.getPosition().x;
	pos_y = body.getPosition().y;
	//speed = 0.05;
	speed= randrangemonster(2, 8) * 0.01;
	dir = randrangemonster(-1,1);
}

Monsters::~Monsters()
{

	
}

void Monsters::update()
{	
	if (dir == 1) body.move(speed, 0);
	else body.move(-speed, 0);
	if (body.getPosition().x > (pos_x + 200)|| body.getPosition().x > 1080) {
		dir = -1;
	}
	else if (body.getPosition().x <( pos_x - 200) || body.getPosition().x < 0) {
		dir = +1;
	}
}

void Monsters::Draw(sf::RenderWindow& window)
{
	
	if (HP > 0) {
		state = true;
	window.draw(body);
	}
	else
	{
	//	state = false;
		HP = 100;
		body.setPosition(randrangemonster(55, 1025), randrangemonster(200, 680));
	}
}
