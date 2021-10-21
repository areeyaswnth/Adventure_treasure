#include "Game.h"

Game::Game()
{
    state = true;
    HPsize_x = 500.0f;
    HPsize_y = 40.0f;
    HP.setPosition(50, 30);
    baseHP.setPosition(45, 25);
    baseHP.setSize(sf::Vector2f(HPsize_x + 10, HPsize_y + 10));
    baseHP.setFillColor(sf::Color::White);
    numbullet = 0;
}

Game::~Game()
{
}

void Game::collision1(int i)
{

    if (player.body.getGlobalBounds().intersects(chest[i].monster.shape.getGlobalBounds())&&chest[i].monster.state&&counttime>=2000&&chest[i].open) {
        player.HP-=5;      
      //  player.body.setFillColor(sf::Color(255, 0, 0, 100));
        clock.restart();
     //   std::cout <<"HP:"<<player.HP<<"\n";
   }    
    else
    {
        player.body.setFillColor(sf::Color(255, 255, 255, 255));
    }
    if (player.body.getGlobalBounds().intersects(chest[i].coin.shape.getGlobalBounds()) && chest[i].open && sf::Keyboard::isKeyPressed(sf::Keyboard::F) && chest[i].coin.state && !chest[i].monster.state) {
        chest[i].box.setTextureRect(sf::IntRect(0, 0, chest[i].box_xsize, chest[i].box_ysize));
        chest[i].open = false;
        chest[i].coin.state = false;
        chest[i].monster.state = false;
        chest[i].randchest();
        player.score += 100;
        ///std::cout << "SCORE:" << player.score << "\n";
    }

}

void Game::collision2(int i)
{

    if (player.body.getGlobalBounds().intersects(monster[i].body.getGlobalBounds()) &&  counttime >= 2000 && monster[i].state ) {
        player.HP-=10;        
        player.body.setFillColor(sf::Color(255, 0, 0, 100));
      //  colortime = colorclock.getElapsedTime().asMilliseconds();
        clock.restart();

    }    
    else
    {
        player.body.setFillColor(sf::Color(255, 255, 255, 255));
    }

}

void Game::HPupdate()
{    
    if (player.HP > 80.0f) {
         HP.setFillColor(sf::Color(41, 183, 135, 255));
    }
    else if (player.HP > 60.0f) {
        HP.setFillColor(sf::Color(159, 218, 64, 255));
    }
    else if (player.HP > 40.0f) {
        HP.setFillColor(sf::Color(250, 253, 15, 255));
    }
    else if (player.HP > 20.0f) {
        HP.setFillColor(sf::Color(255, 165, 0, 255));
    }
    else if (player.HP > 0.0f) {
        HP.setFillColor(sf::Color(255, 64, 16, 255));
    }
    if (player.HP >= 0) {
         HPsize_x = 500.0f - ((100.0f - player.HP) * 5.0f);
    }

    HP.setSize(sf::Vector2f(HPsize_x, HPsize_y));
}

void Game::pewbullet()
{
    timebullet = clockbullet.getElapsedTime().asMilliseconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&timebullet>=300&&!bullet[numbullet].state) {
        bullet[numbullet].state = true;
        bullet[numbullet].pos(player.body.getPosition().x, player.body.getPosition().y,player.dir_bullet);
        numbullet++;
        numbullet = numbullet % 3;
        clockbullet.restart();
    }
}


void Game::collision3(int i, int j)
{
    if (bullet[j].bullet_body.getGlobalBounds().intersects(chest[i].monster.shape.getGlobalBounds()) && chest[i].monster.state && bullet[j].state && chest[i].open)
    {
        bullet[j].state = false;
        chest[i].monster.HP -= 15;
        if (chest[i].monster.HP <= 0)player.score += 50;

    }
}

void Game::collision4(int i, int j)
{
    if (bullet[j].bullet_body.getGlobalBounds().intersects(monster[i].body.getGlobalBounds()) &&bullet[j].state && monster[i].state)
    {
        monster[i].HP -= 15;
        bullet[j].state = false;
        if (monster[i].HP <= 0)player.score += 50;
    }
}

void Game::collision5()
{
}

void Game::gamedraw(sf::RenderWindow& window,float time)
{    

    pewbullet();
    counttime = clock.getElapsedTime().asMilliseconds();
    for (int i = 0; i < 15; i++) {     
        collision1(i);
        for (int j = 0; j < 3; j++)
        {
            collision3(i, j);
        }
        chest[i].Update(player.Collision());
        chest[i].Draw(window,time);
    }
    for (int i = 0; i < 5; i++)
    {
        collision2(i);
        for (int j = 0; j < 3; j++)
        {
            collision4(i, j);
        }
        monster[i].update();
        monster[i].Draw(window);

    }    

    for (int i = 0; i < 3; i++) {    
        itemtime[i] = clockitem[i].getElapsedTime().asSeconds();
        if (itemtime[i] >= 15+(i*5)&&itemtime[i]<=25+(i*5)) {
        item[i].Draw(window);
        item[i].state = true;
        }
        else if (itemtime[i] > 25+(i*5)) {
       // item.Draw(window);
        clockitem[i].restart();
        item[i].state = false;
        item[i].randitem();
        }
    }
    for (int i = 0; i < 3; i++) {
        if(bullet[i].state)bullet[i].Draw(window);
    }
    player.Update(time);
    player.Draw(window,time);    
    HPupdate();

    window.draw(baseHP);
    window.draw(HP);    
   // if (player.HP <= 0); {
   //     state = false;
   // }

}


