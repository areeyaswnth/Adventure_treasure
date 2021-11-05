#include "Background.h"

Background::Background()
{
	bg_texture.loadFromFile("graphics/background.png");
	bg.setSize(size);
	bg.setPosition(0.0f, 0.0f);
	bg.setTexture(&bg_texture);
	menutt.loadFromFile("graphics/bg.png");
	bgmenu.setScale(size);
	bgmenu.setPosition(0.0f, 0.0f);
	bgmenu.setTexture(&menutt);
}

Background::~Background()
{
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
}

void Background::menubg(sf::RenderWindow& window)
{
	window.draw(bgmenu);
}
