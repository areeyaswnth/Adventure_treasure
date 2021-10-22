#include "Item.h"
#include<time.h>
int randforitem(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return int(n);
}
Item::Item()
{	
	texture.loadFromFile("graphics/item.png");
	//heal
	body.setTexture(&texture);
	body.setSize(sf::Vector2f(42.0f,75.0f));
	size_x = texture.getSize().x / 3;
	size_y = texture.getSize().y / 1;
	randitem();
	skillstate = false;

}

Item::~Item()
{
}

void Item::randitem()
{	
	item_type = randforitem(0, 2);
	//if (item_type > 2)item_type = 0;
	pos_x = float(randforitem(55, 1025));
	pos_y = float(randforitem(200, 680));
	body.setPosition(pos_x, pos_y);	
	body.setTextureRect(sf::IntRect(size_x*item_type , 0, size_x, size_y));
}

void Item::Draw(sf::RenderWindow& window)
{
	if(state)window.draw(body);

}
