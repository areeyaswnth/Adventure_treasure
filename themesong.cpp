#include "themesong.h"

themesong::themesong()
{
	buffer.loadFromFile("sound/demo.wav");
	sound.setBuffer(buffer);
	sound.setVolume(1);
}

themesong::~themesong()
{
}

void themesong::Play()
{
	if (sound.getStatus() != sf::Music::Status::Playing) {
		sound.play();
	}
}
