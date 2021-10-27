#include "Howtoplay.h"

Howtoplay::Howtoplay()
{
	font.loadFromFile("font/8Bit2.ttf");	
	sf::Text ttext(" ",font,50);
	main.setCharacterSize(80);
	main.setFillColor(sf::Color::White);
	main.setStyle(sf::Text::Style::Bold);
	main.setPosition(340, 0);
	main.setFont(font);
	main.setString("HOW TO PLAY");
	exit = ttext;
	exit.setCharacterSize(50);
	exit.setFillColor(sf::Color::Red);
	exit.setString("EXIT");
	exit.setPosition(950,650);
	exit.setStyle(sf::Text::Style::Bold);
	monster1();
	monster2();
	item123();
	key();
	chestset();
}

Howtoplay::~Howtoplay()
{

}

void Howtoplay::monster1()
{
	monster[0].texture.loadFromFile("graphics/monster1.png");
	monster[0].body.setTexture(&monster[0].texture);
	monster[0].body.setTextureRect(sf::IntRect(0, 0, 23, 23));
	monster[0].body.setSize(sf::Vector2f(115, 115));
	monster[0].body.setPosition(70, 130);
	monster[0].text[0].setFont(font);
	monster[0].text[0].setFillColor(sf::Color::White);
	monster[0].text[0].setCharacterSize(25);
	monster[0].text[0].setString("Monster(map)\nเมื่อเดินชนจะHP -10\nถ้าฆ่าได้จะได้รับscore +30");
	monster[0].text[0].setPosition(200, 130);
	monster[0].text[0].setStyle(sf::Text::Style::Bold);
}

void Howtoplay::monster2()
{
	monster[1].texture.loadFromFile("graphics/monster2.png");
	monster[1].body.setTexture(&monster[1].texture);
	monster[1].body.setTextureRect(sf::IntRect(0, 0, 23, 23));
	monster[1].body.setSize(sf::Vector2f(115, 115));
	monster[1].body.setPosition(70, 330);
	monster[1].text[0].setFont(font);
	monster[1].text[0].setFillColor(sf::Color::White);
	monster[1].text[0].setCharacterSize(25);
	monster[1].text[0].setString("Monster(chest)\nเมื่อเดินชนจะHP -5\nถ้าฆ่าได้จะได้รับscore +20");
	monster[1].text[0].setPosition(200, 330);
	monster[1].text[0].setStyle(sf::Text::Style::Bold);
}

void Howtoplay::item123()
{
	//item1
	item[0].texture.loadFromFile("graphics/item.png");
	item[0].body.setTexture(&item[0].texture);
	item[0].body.setSize(sf::Vector2f(70.0f, 125.0f));
	int size_x = item[0].texture.getSize().x / 3;
	int size_y = item[0].texture.getSize().y / 1;
	item[0].body.setTextureRect(sf::IntRect(size_x*0, 0, size_x, size_y));
	item[0].body.setPosition(70, 500);
	item[0].text[0].setFont(font);
	item[0].text[0].setFillColor(sf::Color::White);
	item[0].text[0].setCharacterSize(30);
	item[0].text[0].setString("HP+5");
	item[0].text[0].setPosition(70,620 );
	item[0].text[0].setStyle(sf::Text::Style::Bold);
	//item2
	item[1].body.setTexture(&item[0].texture);
	item[1].body.setSize(sf::Vector2f(70.0f, 125.0f));
	item[1].body.setTextureRect(sf::IntRect(size_x * 1, 0, size_x, size_y));
	item[1].body.setPosition(200, 500);
	item[1].text[0].setFont(font);
	item[1].text[0].setFillColor(sf::Color::White);
	item[1].text[0].setCharacterSize(30);
	item[1].text[0].setString("scorex2\n(10 sec)");
	item[1].text[0].setPosition(180, 620);
	item[1].text[0].setStyle(sf::Text::Style::Bold);
	//item3
	item[2].body.setTexture(&item[0].texture);
	item[2].body.setSize(sf::Vector2f(70.0f, 125.0f));
	item[2].body.setTextureRect(sf::IntRect(size_x * 2, 0, size_x, size_y));
	item[2].body.setPosition(330, 500);
	item[2].text[0].setFont(font);
	item[2].text[0].setFillColor(sf::Color::White);
	item[2].text[0].setCharacterSize(30);
	item[2].text[0].setString("score+500");
	item[2].text[0].setPosition(330, 620);
	item[2].text[0].setStyle(sf::Text::Style::Bold);
}

void Howtoplay::key()
{
	player.texture.loadFromFile("graphics/player.png");
	player.body.setTexture(&player.texture);
	player.body.setSize(sf::Vector2f(127.5f, 247.5f));
	player.body.setPosition(900,160);
	int body_xsize = player.texture.getSize().x / 3;
	int body_ysize = player.texture.getSize().y / 4;
	player.body.setTextureRect(sf::IntRect(0, 0, body_xsize, body_ysize));
	int animationFrame = 0;
	keytext.setFont(font);
	keytext.setCharacterSize(30);
	keytext.setFillColor(sf::Color::White);
	keytext.setString("W เคลื่อนที่ขึ้นข้างบน\nA เคลื่อนที่ไปทางซ้าย\nS เคลื่อนที่ลงข้างล่าง\nD เคลื่อนที่ไปทางขวา\nF รับitemหรือcoin\nspacebar ยิงกระสุน\nenter เปิดกล่องสมบัติ\nXเพื่อออก\nRเพื่อเริ่มใหม่");
	keytext.setPosition(540, 130);
	keytext.setStyle(sf::Text::Style::Bold);
}

void Howtoplay::chestset()
{
	chest.texture.loadFromFile("graphics/coin.png");
	chest.body.setTexture(&chest.texture);
	int box_xsize = chest.texture.getSize().x / 5;
	int box_ysize = chest.texture.getSize().y;
	chest.body.setTextureRect(sf::IntRect(0, 0, box_xsize, box_ysize));
	chest.body.setSize(sf::Vector2f(138, 156));
	chest.body.setPosition(480, 540);
	chest.text[0].setFont(font);
	chest.text[0].setFillColor(sf::Color::White);
	chest.text[0].setCharacterSize(30);
	chest.text[0].setString("Coin\nได้รับscore+100");
	chest.text[0].setPosition(620, 580);
	chest.text[0].setStyle(sf::Text::Style::Bold);
}



bool Howtoplay::Exit(sf::RenderWindow& window)
{
	if (exit.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
		return true;
	}
	else
	{
		return false;
	}

}

void Howtoplay::Draw(sf::RenderWindow& window)
{	
	window.draw(chest.body);
	window.draw(chest.text[0]);
	window.draw(player.body);
	window.draw(keytext);
	window.draw(item[0].body);
	window.draw(item[0].text[0]);
	window.draw(item[1].body);
	window.draw(item[1].text[0]);
	window.draw(item[2].body);
	window.draw(item[2].text[0]);
	window.draw(monster[1].text[0]);
	window.draw(monster[1].body);
	window.draw(monster[0].text[0]);
	window.draw(monster[0].body);
	window.draw(main);	
	window.draw(exit);

}

