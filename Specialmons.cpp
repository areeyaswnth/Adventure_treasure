#include "Specialmons.h"
#include<time.h>
float randrangspe(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return float(n);
}
Specialmons::Specialmons()
{
	monstate = false;
	HP = 100;
	texture.loadFromFile("graphics/monster3.png");
	body.setTextureRect(sf::IntRect(0, 0, 23.0f, 26.0f));
	body.setTexture(&texture);
	body.setSize(sf::Vector2f(55.2f, 62.4f));
	body.setPosition(randrangspe(55, 1025), randrangspe(200, 680));
	pos_x = body.getPosition().x;
	pos_y = body.getPosition().y;
	randdir = randrangspe(1,8);
	speed = 0.03f;
}

Specialmons::~Specialmons()
{
}

void Specialmons::update()
{

	if (body.getPosition().x <= 0 || body.getPosition().x >= 1040 || body.getPosition().y <= 100|| body.getPosition().y >=700) {
		pos_x = body.getPosition().x;
		pos_y = body.getPosition().y;
		randdir = randrangspe(1, 6);
	}
	 if(body.getPosition().y-pos_y>100|| body.getPosition().y-pos_y<-100|| body.getPosition().x-pos_x>100||body.getPosition().x-pos_x<-100)
	{
		pos_x = body.getPosition().x;
		pos_y = body.getPosition().y;
		randdir = randrangspe(1, 6);
	}
	if (randdir == 1)body.move(speed, 0);
	else if (randdir == 2)body.move(-speed, 0);
	else if (randdir == 3)body.move(0, speed);
	else if (randdir == 4)body.move(0, -speed);
	else if (randdir == 5)body.move(speed,speed);
	else if (randdir == 6)body.move(-speed, -speed);
	else if (randdir == 7)body.move(-speed, speed);
	else if (randdir == 8)body.move(speed, -speed);
}

void Specialmons::set()
{
	body.setPosition(randrangspe(55, 1025), randrangspe(200, 680));
	pos_x = body.getPosition().x;
	pos_y = body.getPosition().y;
	randdir = randrangspe(1, 8);
}

void Specialmons::Draw(sf::RenderWindow& window)
{
	sf::Clock mon;
	float time;

	if (HP > 0) {
		state = true;
		window.draw(body);
	}
	else
	{
		//time = mon.getElapsedTime().asSeconds();
		//if (time > 10) {
		set();
		HP = 100;
		//mon.restart();
	//	}
		//	state = false;	


	}
}
