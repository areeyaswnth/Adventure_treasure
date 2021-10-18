#include "Bullet.h"

Bullet::Bullet()
{
	texture.loadFromFile("graphics/bullet.png");
	bullet_body.setTexture(&texture);
	bullet_body.setSize(sf::Vector2f(38.0f, 42.0f));
	bullet_body.setTextureRect(sf::IntRect(0, 0, 19, 21));
	state = false;
	dir = 4;
}

Bullet::~Bullet()
{
}



void Bullet::update(float deltatime)
{	
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) ) {
		state = true;	
	}		


}
void Bullet::Draw(sf::RenderWindow& window)
{	
	if (state==true) {
	window.draw(bullet_body);
	bullet_move();
	}		

}

void Bullet::pos(float pos_x, float pos_y,int Dir)
{
	dir = Dir;
	bullet_body.setPosition(pos_x,pos_y+40);
}

void Bullet::bullet_move()
{
	if (dir == 1) bullet_body.move(-0.25f, 0.0f);
	if (dir == 2)	bullet_body.move(0.25f, 0.0f);
	if (dir == 3) bullet_body.move(0.0f, -0.25f);
	if (dir == 4)	bullet_body.move(0.0f, 0.25f);
	if ((bullet_body.getPosition().x <= 0 || bullet_body.getPosition().x >= 1080) || (bullet_body.getPosition().y <= 0 || bullet_body.getPosition().y >= 720)) {
		state = false;
	}
}


