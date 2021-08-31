#include "SoundHandler.h"

SoundManager::SoundManager()
{

	MySounds = new sf::SoundBuffer[3];
	music = new sf::Music;
	sound = new sf::Sound;

	MySounds[0].loadFromFile("sounds/hit.wav");
	MySounds[1].loadFromFile("sounds/navigate.wav");
	MySounds[2].loadFromFile("sounds/lose.wav");


	music->openFromFile("sounds/music.wav");
}

SoundManager::~SoundManager()
{
	delete MySounds;
	delete music;
	delete sound;
}

void SoundManager::PlaySound_Hit()
{
	sound->setBuffer(MySounds[0]);
	sound->play();
}

void SoundManager::PlaySound_Button()
{
	sound->setBuffer(MySounds[1]);
	sound->play();
}

void SoundManager::PlaySound_Lose()
{
	sound->setBuffer(MySounds[2]);
	sound->play();
}

void SoundManager::PlayMusic(bool choice)
{
	if (choice)
	{
		if (music->getStatus() != music->Playing)
			music->play();
	}

	else
	{
		music->stop();
	}
}
