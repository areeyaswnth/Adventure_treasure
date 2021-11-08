#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<SFML/graphics.hpp>
#include <SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
/*
 class that acts as the game engine
 wrapper class
*/



class Game
{
private:
	//variables
	// window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//mouse position
	sf::Vector2i mousePosWindow;
	
	//game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	//game object
	std::vector< sf::RectangleShape > enemies;
	sf::RectangleShape enemy;
	//private functions
	void initVariables();
	void initWindow();
	void initEnemies();
public:
	//constructors/destructor
	Game();
	virtual ~Game();
	//accessors
	const bool running() const;

	//functions
	void spawnEnemy();
	void pollEvents();
	void updateMousePositions();
	void updateEnemies();
	void update();

	void renderEnemies();
	void render();
};
