#pragma once
#include<stdio.h>
#include<vector>
#include<string.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include<algorithm>
#include<sstream>
using namespace std;
class Score
{
public:
	Score();
	~Score();
	void ReadFile();
	void wFile();
	string Pname;	
	int scoreplayer;
	void setscoretext();
	void Drawscore(sf::RenderWindow& window);
private:
	sf::Font font;
	sf::Text main,scoretext[5];
	FILE* fp;
	sf::Text top[5];
	int i;
	char temp[255];
	size_t score[6];
	std::string name[6];
	//std::vector<std::pair<int, std::string>> userScore;
	vector<pair<int, string>> userScore;
	size_t getscore;
	std::string getName;

};

