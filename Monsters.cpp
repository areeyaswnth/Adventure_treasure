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
//	speed = 0.05f;
	speed= randrangemonster(2, 8) * 0.01;
	step = randrangemonster(100, 250);
	dirx = randrangemonster(1,2);
	diry = randrangemonster(1, 2);
}

Monsters::~Monsters()
{

	
}

void Monsters::update()
{	
	if (dirx == 1) body.move(speed, 0);
	else if(dirx==2)  body.move(-speed, 0);
	if (body.getPosition().x > (pos_x + step)|| body.getPosition().x > 1080) {
		dirx = +2;
	}
	else if (body.getPosition().x <( pos_x - step) || body.getPosition().x < 0) {
		dirx = +1;
	}
	if (diry == 1) body.move(0,speed);
	else if (diry == 2)  body.move(0, -speed);
	if (body.getPosition().y > (pos_y + step) || body.getPosition().y > 720) {
		diry = +2;
	}
	else if (body.getPosition().y < (pos_y - step) || body.getPosition().y < 0) {
		diry = +1;
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
