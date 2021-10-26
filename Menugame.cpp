#include "Menugame.h"

Menugame::Menugame()
{
	font.loadFromFile("font/8Bit.ttf");
	misname.loadFromFile("font/8Bit2.ttf");
	Name.setCharacterSize(100);
	Name.setString("Adventure&Treasure");
	Name.setFont(font);
	Name.setPosition(540,100);
	Name.setOrigin(sf::Vector2f(Name.getGlobalBounds().width/2,Name.getGlobalBounds().height / 2));
	Name.setFillColor(sf::Color::White);
	play.setCharacterSize(70);
	play.setString("PLAY");
	play.setFont(font);
	play.setFillColor(sf::Color::White);
	play.setPosition(540, 360);
	play.setOrigin(sf::Vector2f(play.getGlobalBounds().width/2,play.getGlobalBounds().height/2));
	Highscore.setCharacterSize(70);
	Highscore.setString("HIGH SCORE");
	Highscore.setFont(font);
	Highscore.setFillColor(sf::Color::White);
	Highscore.setPosition(540, 460);
	Highscore.setOrigin(sf::Vector2f(Highscore.getGlobalBounds().width / 2, Highscore.getGlobalBounds().height / 2));
	Howto.setCharacterSize(70);
	Howto.setString("HOW TO");
	Howto.setFont(font);
	Howto.setFillColor(sf::Color::White);
	Howto.setPosition(540, 560);
	Howto.setOrigin(sf::Vector2f(Howto.getGlobalBounds().width / 2, Howto.getGlobalBounds().height / 2));
	ary.setFillColor(sf::Color::White);
	ary.setCharacterSize(30);
	ary.setString("64011028 อารียา สุวรรณทศ");
	ary.setOrigin(ary.getGlobalBounds().width / 2, ary.getGlobalBounds().height / 2);
	ary.setPosition(sf::Vector2f(360,680));
	ary.setFont(misname);

}

Menugame::~Menugame()
{
	
}

void Menugame::update(sf::RenderWindow& window)
{
	 if (play.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		play.setFillColor(sf::Color(255, 255, 255, 0));
	}
	else if (play.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		play.setFillColor(sf::Color(255, 255, 255, 100));
	}
	else
	{
		play.setFillColor(sf::Color::White);
	}
	if (Howto.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		Howto.setFillColor(sf::Color(255, 255, 255, 100));
	}
	else
	{
		Howto.setFillColor(sf::Color::White);
	}
	if (Highscore.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		Highscore.setFillColor(sf::Color(255, 255, 255, 100));
	}
	else
	{
		Highscore.setFillColor(sf::Color::White);
	}
}

void Menugame::mouseclick(sf::RenderWindow& window)
{

}
void Menugame::Draw(sf::RenderWindow& window)
{
	update(window);
	window.draw(ary);
	window.draw(Howto);
	window.draw(Highscore);
	window.draw(play);
	window.draw(Name);
}

