#include "Game.h"

Game::Game()
{
   
}

Game::~Game()
{
}

void Game::collision1(int i)
{
    counttime = clock.getElapsedTime().asMilliseconds();
    if (counttime > 800) {
        clock.restart();
    }
    if (player.body.getGlobalBounds().intersects(chest[i].monster.shape.getGlobalBounds())&&chest[i].monster.state&&counttime>=800&&chest[i].open) {
        player.HP-=5;
        std::cout <<"HP:"<<player.HP<<"\n";
   }
    if (player.bullet.bullet_body.getGlobalBounds().intersects(chest[i].monster.shape.getGlobalBounds()) && chest[i].monster.state&&player.bullet.state&&chest[i].open)
    {
        player.bullet.state = false;
        chest[i].monster.HP -= 10;
        if (chest[i].monster.HP <= 0)player.score += 50;
    }
    if (player.body.getGlobalBounds().intersects(chest[i].coin.shape.getGlobalBounds()) && chest[i].open && sf::Keyboard::isKeyPressed(sf::Keyboard::F) && chest[i].coin.state && !chest[i].monster.state) {
        chest[i].box.setTextureRect(sf::IntRect(0, 0, chest[i].box_xsize, chest[i].box_ysize));
        chest[i].open = false;
        chest[i].coin.state = false;
        chest[i].monster.state = false;
        chest[i].randchest();
        player.score += 100;
        std::cout << "SCORE:" << player.score << "\n";
    }
}

void Game::collision2(int i)
{
    counttime = clock.getElapsedTime().asMilliseconds();
    if (counttime >800) {
        clock.restart();
    }
    if (player.body.getGlobalBounds().intersects(monster[i].body.getGlobalBounds()) &&  counttime >= 800 && monster[i].state ) {
        player.HP-=10;
        std::cout << "HP:" << player.HP << "\n";
    }
    if (player.bullet.bullet_body.getGlobalBounds().intersects(monster[i].body.getGlobalBounds())  && player.bullet.state&&monster[i].state)
    {
        monster[i].HP -= 15;
        player.bullet.state = false;
        if(monster[i].HP<=0)player.score += 50;
    }
}




void Game::gamedraw(sf::RenderWindow& window,float time)
{    

    for (int i = 0; i < 15; i++) {    
        collision1(i);
        chest[i].Update(player.Collision());
        chest[i].Draw(window,time);
    }
    for (int i = 0; i < 5; i++)
    {
        collision2(i);
        monster[i].update();
        monster[i].Draw(window);

    }
    player.Update(time);
    player.Draw(window,time);
}
