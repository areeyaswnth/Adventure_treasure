#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Chest {
public:
	Chest();
	~Chest();

	void Update(sf::FloatRect p1);
	void Draw(sf::RenderWindow& window,float time);
	void randchest();
	void monster_move();	
	struct MyStruct1
	{
		bool state;
		sf::Texture texture;
		sf::RectangleShape shape;
	}coin;	
	struct MyStruct2
	{
		float speed;
		int HP=50;
		bool state;
		int max=3;
		sf::Texture texture;
		sf::RectangleShape shape;

	}monster;	
	bool open;
private:
	sf::Texture chest_texture;
	sf::RectangleShape box;
	bool faceRight;
	int box_xsize;
	int box_ysize;
	int animationFrame;

	int dir = 1;
	int type_box;


	
};