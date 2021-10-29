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
    //text    
    font.loadFromFile("font/8Bit.ttf");
    sf::Text ttext("score", font, 60);
    textscore = ttext;
    score = ttext;
    gameover = ttext;
    score.setString("0000000");
    HPsize_x = 500.0f;
    HPsize_y = 40.0f;
    HP.setPosition(50, 30);
    baseHP.setPosition(45, 25);
    baseHP.setSize(sf::Vector2f(HPsize_x + 10, HPsize_y + 10));
    baseHP.setFillColor(sf::Color::White);
    numbullet = 0;
    player.scorebonus = 1.0f;
    skilltime[0] = 0;
    item[0].skillstate = false;
    int countover=0;

}

Game::~Game()
{

}

void Game::scoreupdate()
{
    std::stringstream ss;
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
        chest[i].randchest();
        player.score += (100*player.scorebonus);
     //   std::cout << "SCORE:" << player.score << "\n";
    }

}

void Game::collision2(int i)
{

    if (player.body.getGlobalBounds().intersects(monster[i].body.getGlobalBounds()) &&  counttime >= 2000 && monster[i].state ) {
        player.HP-=10;
        sound[0].setVolume(20);
        sound[0].play();
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
         //   std::cout << "SCORE:" << player.score << "\n";
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
           // std::cout << "SCORE:" << player.score << "\n";
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
    player.HP = 100;
    player.score = 0;
    countover = 0;
}

void Game::playername()
{
    if (event.type==sf::Event::TextEntered)
    {
        username.push_back(event.text.unicode);
        cout <<event.text.unicode;
    }
}


void Game::gamedraw(sf::RenderWindow& window,float time)
{
    if (player.HP>0)
    {   
        itemtime[0] = clockitem[0].getElapsedTime().asSeconds();
        pewbullet();
        counttime = clock.getElapsedTime().asMilliseconds();
     //monster-map
        for (int i = 0; i < 15; i++) {
            collision1(i);
            for (int j = 0; j < 3; j++)
            {
                collision3(i, j);
            }
            chest[i].Update(player.Collision());
            chest[i].Draw(window, time);
        }
    //monster-shape
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

        //bullet
        for (int i = 0; i < 3; i++) {
            if (bullet[i].state)bullet[i].Draw(window);
        }
        if (itemtime[0] > 5) {
            if (!item[0].state) {
                item[0].randitem();
                item[0].state = true;
            }
            item[0].Draw(window);
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
        state = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
            player.HP = 0;
        }
    }
    else if(player.HP<=0)
    {
        playername();
        over();

        if (sound[5].getStatus()!= sf::Music::Status::Playing&&countover!=1) {
            sound[5].play();
            countover=1;
        }
        window.draw(gameover);
    }
       

}


