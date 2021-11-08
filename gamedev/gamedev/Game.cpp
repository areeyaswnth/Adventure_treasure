
#include "Game.h"

//private funtions
void Game::initVariables()
{	
	this->window = nullptr;
	// game logic

	this->points = 0;	
	this->enemySpawnTimerMax = 1000.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;

	this->maxEnemies = 5;
}
void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);

}
void Game::initEnemies()
{
	this->enemy.setPosition(300.f,400.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.5f,0.5f));
	this->enemy.setFillColor(sf::Color::Yellow);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);


}
//constructors/destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
}
Game::~Game() {
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

//function
void Game::spawnEnemy()
{
	/*
		@return void
		Spawn enemies and sets their color and positions.
		-Sets a  random color.
		-Sets a  random position.
		-Adds enemy to the vectors;
	*/
	this->enemy.setPosition(
		static_cast<float>(rand()%	static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
		0.f
	);
	this->enemy.setFillColor(sf::Color::Green);
	//spawn enemy
	this->enemies.push_back(this->enemy);
	//removes enemies at and of the screen
}

void Game::pollEvents()
{
	//event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
			this->window->close();
			break;

		}

	}
}

void Game::updateMousePositions()
{
	/*
	 @ return void
	
	* updates the mouse positions:
	*	mouse position relative to window(Vector2i)
	*/
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::updateEnemies()
{
	/*
	 @return void
	 updates the enemy spawn timer and spawns enemies
	 when the total amount of enemies is smaller than the maximum.
	 moves the enemies downward.
	 Removes the enemies at the edge of the screen.//TODO
	*/
	//updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies) {
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
			//spawn this enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}	
		else
			this->enemySpawnTimer += 1.f;
	}
	//move the enemies
	for (auto &e : this->enemies)
	{
		e.move(0.f, 1.f);
	}

}
void Game::renderEnemies()
{	
	//rendering all the enemies
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
}

//function
void Game::update()
{
	this->pollEvents();
	this->updateMousePositions(); 
	this->updateEnemies();

}


void Game::render()
{
	/*
		@return
		-clear old frame
		-renderobject
		-display frame in window
	render this game object
	*/
	this->window->clear();
	//draw game objects
	this->renderEnemies();

	this->window->display();
}

