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
		int animation;
	}coin;	
	struct MyStruct2
	{
		float speed;
		int HP;
		bool state;
		sf::Texture texture;
		sf::RectangleShape shape;	
		

	}monster;	
	bool open;	
	sf::RectangleShape box;	
	int box_xsize;
	int box_ysize;
private:
	sf::Clock clock;
	float timeC;
	sf::Texture chest_texture;
	bool faceRight;
	int animationFrame;
	int dir = 1;
	int type_box;


	
};