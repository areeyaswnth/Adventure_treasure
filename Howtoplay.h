#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
class Howtoplay
{
public:
	Howtoplay();
	~Howtoplay();
	void monster1();
	void monster2();
	void item123();
	void key();
	void chestset();
	void Draw(sf::RenderWindow& window);
	bool Exit(sf::RenderWindow& window);
	sf::Text exit;
private:
	//sf::SoundBuffer buffer;
	//sf::Sound clicksound;
	sf::Font font;
	sf::Text main,keytext;
	struct fortext
	{
		sf::Texture texture;
		sf::RectangleShape body;
		sf::Text text[1];
	}monster[2],item[3],player,chest;

};

