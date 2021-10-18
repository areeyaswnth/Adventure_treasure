#include "Chest.h"
#include<time.h>
using namespace std;

float randrange(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return float(n);
}
Chest::Chest()
{
	chest_texture.loadFromFile("graphics/chest.png");
	box.setTexture(&chest_texture);
	box.setSize(sf::Vector2f(55.20f, 62.4f));
	box_xsize = chest_texture.getSize().x / 2;
	box_ysize = chest_texture.getSize().y;
	box.setTextureRect(sf::IntRect(0, 0, box_xsize, box_ysize));
	animationFrame = 0;
	//coin
	coin.texture.loadFromFile("graphics/coin.png");
	coin.shape.setTextureRect(sf::IntRect(0, 0, box_xsize, box_ysize));
	coin.shape.setTexture(&coin.texture);
	coin.state = false;
	coin.shape.setSize(sf::Vector2f(55.20f, 62.4f));
	//monster
	monster.texture.loadFromFile("graphics/monster2.png");
	monster.shape.setTextureRect(sf::IntRect(0, 0, box_xsize, box_ysize));
	monster.shape.setTexture(&monster.texture);
	monster.shape.setSize(sf::Vector2f(55.2f, 62.4f));
	monster.speed = randrange(3, 5) * 0.01;
	monster.state = false;
	randchest();
	//
	open = false;
}

Chest::~Chest()
{
}

void Chest::Update(sf::FloatRect p1)
{

	if (box.getGlobalBounds().intersects(p1)&& sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&&coin.state==false&&open==false) {
		box.setTextureRect(sf::IntRect(box_xsize, 0, box_xsize, box_ysize));
		open = true;
		coin.state = true;		
	}
}

void Chest::Draw(sf::RenderWindow& window,float time)
{
		window.draw(box);
		if (open&&coin.state) {
			window.draw(coin.shape);
		}
		if (open&&monster.state&&coin.state&&monster.HP>0)
		{
			window.draw(monster.shape);
			monster_move();
		}
		if(monster.HP<=0)
		{
			monster.state = false;
		}
}
void Chest::monster_move() {
		if (dir == 1) monster.shape.move(monster.speed, 0);
		else monster.shape.move(-monster.speed, 0);
		if(monster.shape.getPosition().x>box.getPosition().x+60){
			dir =-1;	 
		}
		if (monster.shape.getPosition().x <box.getPosition().x - 60) {
			dir = +1;
		}
}

void Chest::randchest()
{	int random = randrange(1, 3);
	box.setPosition(randrange(55,1025 ), randrange(200, 680));
	coin.shape.setPosition(box.getPosition().x,box.getPosition().y);
	monster.shape.setPosition(box.getPosition().x+60, box.getPosition().y);
	if (random ==1) {
		monster.state =true ;
		monster.HP = 50;
	}

}


