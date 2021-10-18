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
    if (player.body.getGlobalBounds().intersects(chest[i].monster.shape.getGlobalBounds())&&chest[i].monster.state==true&&counttime>=800 && chest[i].open == true) {
        player.HP-=5;
        std::cout <<"HP:"<<player.HP<<"\n";
   }
    if (player.bullet.bullet_body.getGlobalBounds().intersects(chest[i].monster.shape.getGlobalBounds()) && chest[i].monster.state == true &&player.bullet.state==true&&chest[i].open==true)
    {
        player.bullet.state = false;
        chest[i].monster.HP -= 10;
    }
}

void Game::collision2(int i)
{
    counttime = clock.getElapsedTime().asMilliseconds();
    if (counttime >800) {
        clock.restart();
    }
    if (player.body.getGlobalBounds().intersects(monster[i].body.getGlobalBounds()) &&  counttime >= 800 && monster[i].state == true) {
        player.HP-=10;
        std::cout << "HP:" << player.HP << "\n";
    }
    if (player.bullet.bullet_body.getGlobalBounds().intersects(monster[i].body.getGlobalBounds())  && player.bullet.state == true&&monster[i].state==true)
    {
        monster[i].HP -= 15;
        player.bullet.state = false;
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
