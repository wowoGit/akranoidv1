#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "constants.h"

struct SoundManager
{
	sf::SoundBuffer* MySounds;
	sf::Music* music;
	sf::Sound* sound;
	SoundManager();
	~SoundManager();
	void PlaySound_Hit();
	void PlaySound_Button();
	
	void PlaySound_Lose();
	void PlayMusic(bool choice);
};
