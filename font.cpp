#include "font.h"
#include <SFML/Graphics.hpp>
#include <sstream>
font::font()
{
	textfont.loadFromFile("font/8bit.ttf");
	scoretext.setFont(textfont);
	HPtext.setFont(textfont);
	scoretext.setCharacterSize(100);
	HPtext.setCharacterSize(100);
	scoretext.setFillColor(sf::Color::White);
	HPtext.setFillColor(sf::Color::White);
	textRect = scoretext.getGlobalBounds();
	textRect = HPtext.getGlobalBounds();
	scoretext.setOrigin(sf::Vector2f(800.0f, 0.0f));
	HPtext.setOrigin(sf::Vector2f(0.0f, 0.0f));	
	HPtext.setString("HP::");
	scoretext.setString("SCORE::");
}

font::~font()
{
}

void font::printfont(int score, int HP, sf::RenderWindow& window)
{

	window.draw(scoretext);
	
}
