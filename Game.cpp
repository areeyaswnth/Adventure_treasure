#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include<sstream>
#include<string.h>
using namespace sf;
using namespace std;
Game::Game()
{
    //sound
    buffer[0].loadFromFile("sound/Hit.wav");
    sound[0].setBuffer(buffer[0]);
    buffer[1].loadFromFile("sound/item.wav");
    sound[1].setBuffer(buffer[1]);
    buffer[2].loadFromFile("sound/monsdie.wav");
    sound[2].setBuffer(buffer[2]);
    buffer[3].loadFromFile("sound/coin.wav");
    sound[3].setBuffer(buffer[3]);
    buffer[4].loadFromFile("sound/bullet.wav");
    sound[4].setBuffer(buffer[4]);
    buffer[5].loadFromFile("sound/over.wav");
    sound[5].setBuffer(buffer[5]);
    sound[5].setVolume(20);
    buffer[6].loadFromFile("sound/level.wav");
    sound[6].setBuffer(buffer[6]);
    sound[6].setVolume(20);
    //text    
    font.loadFromFile("font/8Bit.ttf");
    sf::Text ttext("score", font, 60);
    Level = ttext;
    textscore = ttext;
    score = ttext;
    gameover = ttext;
    Level.setString("LEVEL : 0");
    score.setString("0000000");
    HPsize_x = 500.0f;
    HPsize_y = 40.0f;
    HP.setPosition(50, 30);
    baseHP.setPosition(45, 25);
    baseHP.setSize(sf::Vector2f(HPsize_x + 10, HPsize_y + 10));
    baseHP.setFillColor(sf::Color::White);    
    Level.setPosition(50, 60);
    Level.setFillColor(sf::Color::White);
    numbullet = 0;
    player.scorebonus = 1.0f;
    skilltime[0] = 0;
    item[0].skillstate = false;
    int countover=0;
    level = 0;
    chest_count = 0;
    monstermax = 0;
    chestmax = 1;

}

Game::~Game()
{

}

void Game::level_update()
{

     if(chest_count>=40)
    {
        if (chest_count == 40)sound[6].play();
        monstermax = 5;
        chestmax = 15;
        level = 10;
    }
    else if (chest_count >= 30)
    {
        if (chest_count == 30)sound[6].play();
        monstermax = 4;
        chestmax = 10;
        level = 9;
    }
    else if (chest_count >= 26)
    {
        if (chest_count == 26)sound[6].play();
        monstermax = 4;
        chestmax = 9;
        level = 8;
    }
    else if (chest_count >= 24)
    {
        if (chest_count == 24)sound[6].play();
        monstermax = 3;
        chestmax = 8;
        level = 7;
    }
    else if (chest_count >= 20)
    {
        if (chest_count == 20)sound[6].play();
        monstermax = 3;
        chestmax = 7;
        level = 6;
    }
    else if (chest_count >= 16)
    {
        if (chest_count == 16)sound[6].play();
        monstermax = 3;
        chestmax = 6;
        level = 5;
    }
    else if (chest_count >= 12)
    {
        if (chest_count == 12)sound[6].play();
        monstermax = 2;
        chestmax = 5;
        level = 4;
    }
    else if (chest_count >= 8)
    {
        if (chest_count == 8)sound[6].play();
        monstermax = 2;
        chestmax = 4;
        level = 3;
    }
    else if (chest_count >= 5)
    {
        if (chest_count == 5)sound[6].play();
        monstermax = 2;
        chestmax = 3;
        level = 2;
    }
    else if (chest_count >= 1)
    {
        if(chest_count==1)sound[6].play();
        monstermax = 1;
        chestmax = 2;
        level = 1;
    }
    else if (chest_count >= 0)
     {
         monstermax=0;
         chestmax = 1;
         level = 0;
     }
     leveluptext();
}

void Game::scoreupdate()
{
    stringstream ss;
    ss << player.score;
    std::string str = ss.str();
    while (str.length() < 6) {
        str.insert(0, "0");
    }
    score.setString(str);
    textscore.setPosition(940,0);
    score.setCharacterSize(90);
    score.setPosition(830, 30);

}

void Game::collision1(int i)
{

    if (player.body.getGlobalBounds().intersects(chest[i].monster.shape.getGlobalBounds())&&chest[i].monster.state&&counttime>=2000&&chest[i].open) {
        player.HP-=5;   
        sound[0].setVolume(20);
        sound[0].play();
        clock.restart();
   }    

    if (player.body.getGlobalBounds().intersects(chest[i].coin.shape.getGlobalBounds()) && chest[i].open && sf::Keyboard::isKeyPressed(sf::Keyboard::F) && chest[i].coin.state && !chest[i].monster.state) {
        sound[3].setVolume(20);
        sound[3].play();
        chest[i].box.setTextureRect(sf::IntRect(0, 0, chest[i].box_xsize, chest[i].box_ysize));
        chest[i].open = false;
        chest[i].coin.state = false;
        chest[i].monster.state = false;
        chest[i].set();
        chest_count++;
        level_update();
        player.score += (100*player.scorebonus);        
    }

}

void Game::collision2(int i)
{

    if (player.body.getGlobalBounds().intersects(monster[i].body.getGlobalBounds()) &&  counttime >= 2000 && monster[i].state ) {
        player.HP-=10;
        sound[0].setVolume(20);
        sound[0].play();
        player.body.setFillColor(sf::Color(255, 0, 0, 100));
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
        sound[4].setVolume(40); 
        sound[4].play();
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
        if (chest[i].monster.HP <= 0)
        {
            player.score += (20 * player.scorebonus);
            sound[2].setVolume(20);
            sound[2].play();
        }
    }
}

void Game::collision4(int i, int j)
{
    if (bullet[j].bullet_body.getGlobalBounds().intersects(monster[i].body.getGlobalBounds()) &&bullet[j].state && monster[i].state)
    {
        monster[i].HP -= 15;
        bullet[j].state = false;
        if (monster[i].HP <= 0)
        {
            sound[2].setVolume(20);
            sound[2].play();
            player.score += (30 * player.scorebonus);
        }
    }
}

void Game::collision5(int i)
{
    skilltime[i] = skillclock[i].getElapsedTime().asSeconds();
    if (item[i].body.getGlobalBounds().intersects(player.body.getGlobalBounds())&&item[i].state&&sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        if (item[i].item_type == 0) {
            if(player.HP<=95) player.HP += 5;       
            item[i].state = false;
            clockitem[i].restart();
        }
        if (item[i].item_type==1)
        {         
            player.scorebonus = 2.0f;
            skills[i] = 1;
            item[i].state = false;
            item[i].skillstate = true;
            skillclock[i].restart();
            clockitem[i].restart();
        }
        if (item[i].item_type == 2) {  
            player.score += 500;
            item[i].state = false;
            clockitem[i].restart();
        }
        sound[1].setVolume(10);
        sound[1].play();
    }                    
    if (skilltime[i]<10&&item[i].skillstate)
    {
            player.scorebonus = 2.0f;
     }
    if (skilltime[i] >= 10 && item[i].skillstate) {
            player.scorebonus = 1.0f;
    }
}

void Game::leveluptext()
{
    std::stringstream ss;
    ss << "Level :" << level;
    std::string str = ss.str();
    Level.setString(str);
}

bool Game::over()
{
    gameover.setString("GAME OVER");
    gameover.setCharacterSize(100);    
    gameover.setOrigin(gameover.getGlobalBounds().width/2, gameover.getGlobalBounds().height/2);
    gameover.setPosition(540, 360);         
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)&&player.HP<=0) {
        return true;
    }
    else
    {
        return false;
    }
}

void Game::reset()
{
    level = 0;
    chest_count = 0;
    player.HP = 100;
    player.score = 0;
    countover = 0;
    level_update();
    player.body.setPosition(540, 360);
    player.animationFrame = 0;
}



void Game::gamedraw(sf::RenderWindow& window,float time)
{

    if (player.HP>0)
    {   
        itemtime[0] = clockitem[0].getElapsedTime().asSeconds();
        pewbullet();
        counttime = clock.getElapsedTime().asMilliseconds();
     //monster-chest
        for (int i = 0; i < chestmax ; i++) {
            if (!chest[i].cheststate) {
                chest[i].set();
                chest[i].cheststate = true;
            }
            collision1(i);
            for (int j = 0; j < 3; j++)
            {
                collision3(i, j);
            }    
            chest[i].level= level;
            chest[i].Update(player.Collision());
            chest[i].Draw(window, time);
        }
    //monster-shape
        for (int i = 0; i < monstermax; i++)
        {
            if (!monster[i].monstate) {
                monster[i].set();
                monster[i].monstate= true;
            }
            collision2(i);
            for (int j = 0; j < 3; j++)
            {
                collision4(i, j);
            }
            monster[i].level = level;
            monster[i].update();
            monster[i].Draw(window);

        }

        //bullet
        if (level >= 4) {
        if (itemtime[0] > 5) {
            if (!item[0].state) {
                item[0].randitem();
                item[0].state = true;
            }
            item[0].Draw(window);
        } 
        }
      
        for (int i = 0; i < 3; i++) {
            if (bullet[i].state)bullet[i].Draw(window);
        }
        collision5(0);
        player.Update(time);
        player.Draw(window, time);
        HPupdate();
        window.draw(baseHP);
        window.draw(HP);
        scoreupdate();        
        window.draw(textscore);
        window.draw(score);
        window.draw(Level);
        state = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
            player.HP = 0;
        }
    }
    else if(player.HP<=0)
    {
        scorep = player.score;
        over();

        if (sound[5].getStatus()!= sf::Music::Status::Playing&&countover!=1) {
            sound[5].play();
            countover=1;
        }
        window.draw(gameover);
    }
       

}


