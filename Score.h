#pragma once
#include<iostream>
#include<vector>
#include<string.h>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include<algorithm>
class Score
{
public:
	Score();
	~Score();
	void ReadFile();

private:
	sf::Font font;
	sf::Text top[5];
	int i;
	std::fstream scorefile;
	char temp[255];
	size_t score[6];
	std::string name[6];
	std::vector<std::pair<int, std::string>> userScore;
	size_t getscore;
	std::string getName;

};

