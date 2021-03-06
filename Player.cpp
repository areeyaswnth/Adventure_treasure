#define _CRT_SECURE_NO_WARNINGS
#include "Player.h"
#include<iostream>
using namespace std;
Player::Player() 
{
	player_texture.loadFromFile("graphics/player.png");
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(51.0f, 99.0f));
	body.setPosition(540, 360);
	body.setTexture(&player_texture);                                                                            
	body_xsize = player_texture.getSize().x / 3;
	body_ysize = player_texture.getSize().y / 4;
	body.setTextureRect(sf::IntRect(0, 0,body_xsize,body_ysize));	
	animationFrame=0;
	dir_bullet = 4;
	HP = max_HP;
	score = 0;

}

Player::~Player()
{
}

void Player::Update(float deltatime)
{		pTime = pClock.getElapsedTime().asMilliseconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&deltatime>20 &&body.getPosition().x>0) {
		body.setTextureRect(sf::IntRect(body_xsize*animationFrame, body_ysize * 2, body_xsize, body_ysize));
		body.move(-4.f, 0.f);
		dir_bullet = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&deltatime > 20&&body.getPosition().x <1030)
		{
		body.move(+4.f, 0.f);
		body.setTextureRect(sf::IntRect(body_xsize * animationFrame, body_ysize * 1, body_xsize, body_ysize));
		dir_bullet = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && deltatime > 20&& body.getPosition().y>87 ) {
		body.move(0.f, -4.0f);
		body.setTextureRect(sf::IntRect(body_xsize * animationFrame, body_ysize * 3, body_xsize, body_ysize));
		dir_bullet = 3;
	}
		
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && deltatime > 20&& body.getPosition().y <620) {
		body.move(0.f, +4.0f);
		body.setTextureRect(sf::IntRect(body_xsize * animationFrame, body_ysize * 0, body_xsize, body_ysize));
		dir_bullet = 4;
	}
	if (pTime> 100) {
	animationFrame++;
	pClock.restart();
	}

	if (animationFrame >=3) {
		animationFrame = 0;
	}		
	

}

void Player::Draw(sf::RenderWindow& window, float deltatime)
{
	window.draw(body);
}

sf::FloatRect Player::Collision()
{
	return body.getGlobalBounds();
}
