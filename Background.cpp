#include "Background.h"

Background::Background()
{
	bg_texture[0].loadFromFile("graphics/background1.png");
	bg_texture[1].loadFromFile("graphics/background2.png");
	bg_texture[2].loadFromFile("graphics/background3.png");
	bg.setSize(size);
	bg.setPosition(0.0f, 0.0f);
	bg.setTexture(&bg_texture[0]);	

	menutt.loadFromFile("graphics/bg.png");
	bgmenu.setSize(size);
	bgmenu.setPosition(0.0f, 0.0f);
	bgmenu.setTexture(&menutt);

	score.loadFromFile("graphics/score.png");
	bgscore.setSize(size);
	bgscore.setPosition(0.0f, 0.0f);
	bgscore.setTexture(&score);


	howto.loadFromFile("graphics/howto.png");
	bghowto.setSize(size);
	bghowto.setPosition(0.0f, 0.0f);
	bghowto.setTexture(&howto);
	}

Background::~Background()
{
}

void Background::Draw(sf::RenderWindow& window)
{
	if(level>3)	bg.setTexture(&bg_texture[1]);
	if (level > 6)	bg.setTexture(&bg_texture[2]);
	window.draw(bg);
}

void Background::menubg(sf::RenderWindow& window)
{

	window.draw(bgmenu);
}

void Background::scorebg(sf::RenderWindow& window)
{
	window.draw(bgscore);
}

void Background::howtobg(sf::RenderWindow& window)
{
	
	window.draw(bghowto);
}
