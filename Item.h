#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Item
{
public: 
	Item();
	~Item();
	void randitem();
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape body;	
	int item_type;	
	bool	state;
	bool  skillstate;
private:
	sf::Texture texture;

	float size_x;
	float size_y;
	float pos_x;
	float pos_y;
	//0=heal,1=score,2=bullet


};

