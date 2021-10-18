#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
class font
{
public:
	font();
	~font();
	void printfont(int score, int HP, sf::RenderWindow& window);
private:
	sf::Font textfont;
	sf::Text scoretext;
	sf::Text HPtext;
	sf::FloatRect textRect;

};

