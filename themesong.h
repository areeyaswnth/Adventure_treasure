#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
class themesong
{
public:
	themesong();
	~themesong();
	void Play();
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

