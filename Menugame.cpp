#include "Menugame.h"
Menugame::Menugame()
{
	
	font.loadFromFile("font/8Bit.ttf");
	misname.loadFromFile("font/8Bit2.ttf");
	Name.setCharacterSize(100);
	Name.setString("Adventure&\nTreasure");
	Name.setFont(font);
	Name.setPosition(50,50);
//	Name.setOrigin(sf::Vector2f(Name.getGlobalBounds().width/2,Name.getGlobalBounds().height / 2));
	Name.setFillColor(sf::Color::White);
	play.setCharacterSize(70);
	play.setString("PLAY");
	play.setFont(font);
	play.setFillColor(sf::Color::White);
	play.setPosition(50, 360);
//	play.setOrigin(sf::Vector2f(play.getGlobalBounds().width/2,play.getGlobalBounds().height/2));
	Highscore.setCharacterSize(70);
	Highscore.setString("HIGH SCORE");
	Highscore.setFont(font);
	Highscore.setFillColor(sf::Color::White);
	Highscore.setPosition(50, 460);
//	Highscore.setOrigin(sf::Vector2f(Highscore.getGlobalBounds().width / 2, Highscore.getGlobalBounds().height / 2));
	Howto.setCharacterSize(70);
	Howto.setString("HOW TO");
	Howto.setFont(font);
	Howto.setFillColor(sf::Color::White);
	Howto.setPosition(50, 560);
//	Howto.setOrigin(sf::Vector2f(Howto.getGlobalBounds().width / 2, Howto.getGlobalBounds().height / 2));
	ary.setFillColor(sf::Color::White);
	ary.setCharacterSize(30);
	ary.setString("ภาพ&GAME by 64011028 อารียา สุวรรณทศ");
//	ary.setOrigin(ary.getGlobalBounds().width / 2, ary.getGlobalBounds().height / 2);
	ary.setPosition(sf::Vector2f(50,680));
	ary.setFont(misname);
	menu_state = true;
	game_state = false;
	howto_state = false;
	highscore_state = false;
	buffer.loadFromFile("sound/click.wav");
	clicksound.setBuffer(buffer);
	clicksound.setVolume(20);
}

Menugame::~Menugame()
{
	
}

void Menugame::update(sf::RenderWindow& window)
{
	 if (play.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)&&menu_state) {
		clicksound.play();
		play.setFillColor(sf::Color(255, 255, 255, 0));	
		menu_state = false;	
		game_state = true;
	}
	else if (play.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)&&menu_state) {
		play.setFillColor(sf::Color(255, 255, 255, 100));
	}
	else
	{
		play.setFillColor(sf::Color::White);
	}
	if (Howto.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)&& sf::Mouse::isButtonPressed(sf::Mouse::Left) &&menu_state) {
		clicksound.play();
		howto_state = true;
		menu_state = false;
		Howto.setFillColor(sf::Color(255, 255, 255,0));
	}
	else if (Howto.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && menu_state) {
		Howto.setFillColor(sf::Color(255, 255, 255, 100));
	}
	else
	{
		Howto.setFillColor(sf::Color::White);
	}
	if (Highscore.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)&& sf::Mouse::isButtonPressed(sf::Mouse::Left)&&menu_state) {
		clicksound.play();
		Highscore.setFillColor(sf::Color(255, 255, 255, 0));
	}
	else if (Highscore.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && menu_state) {
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
	if (menu_state) {
	update(window);
	backgrounds.Draw(window);
	window.draw(ary);
	window.draw(Howto);
	window.draw(Highscore);
	window.draw(play);
	window.draw(Name);
	}
	if (game_state && !menu_state) {
		deltaTime = clock[0].getElapsedTime().asMilliseconds();
		if (deltaTime > 15) {
			clock[0].restart();
		}
		backgrounds.Draw(window);
		game.gamedraw(window, deltaTime);
		if (game.over()) {
			game.reset();
			game_state = false;
			menu_state = true;
		}
	}
	if (howto_state && !menu_state) {
		backgrounds.Draw(window);
		howto.Draw(window);
		if (howto.Exit(window)) {
			howto_state = false;
			menu_state = true;

		}

	}

}

