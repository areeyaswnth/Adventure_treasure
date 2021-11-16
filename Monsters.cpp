#include "Monsters.h"
#include<time.h>
using namespace std;

float randrangemonster(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return float(n);
}

Monsters::Monsters()
{
	monstate = false;
	HP = 100;
	texture.loadFromFile("graphics/monster1.png");
	body.setTextureRect(sf::IntRect(0, 0, 23.0f, 26.0f));
	body.setTexture(&texture);
	body.setSize(sf::Vector2f(55.2f, 62.4f));
//	speed = 0.05f;
}

Monsters::~Monsters()
{

	
}

void Monsters::update()
{	
	if ((level >= 3 && (randtype == 3 || randtype == 1)) || (level < 3)) {
	if (dirx == 1) body.move(speed, 0);
	else if(dirx==2)  body.move(-speed, 0);
	}
	if (body.getPosition().x > (pos_x + step)) dirx = +2;
	else if (body.getPosition().x <( pos_x - step)) dirx = +1;
	if(body.getPosition().x > 1040)	dirx = +2;
	if (body.getPosition().x < 0) dirx = +1;

	if ((level >=3&&(randtype==2))||(level>=8&&(randtype==3))) {
	if (diry == 1) body.move(0, speed);
	else if (diry == 2)  body.move(0, -speed);
	if (body.getPosition().y > (pos_y + step) || body.getPosition().y > 700) {
		diry = +2;
	}
	else if (body.getPosition().y < (pos_y - step) || body.getPosition().y < 150) {
		diry = +1;
	}
	}

}

void Monsters::set()
{
	
	speed = randrangemonster(5, 7) * 0.01;
	step = randrangemonster(300, 500);
	dirx = randrangemonster(1, 2);
	diry = randrangemonster(1, 2);
	randtype = randrangemonster(1, 3);
	body.setPosition(randrangemonster(55, 1025), randrangemonster(200, 680));
	pos_x = body.getPosition().x;
	pos_y = body.getPosition().y;
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
		set();
		HP = 100;

	}
}

