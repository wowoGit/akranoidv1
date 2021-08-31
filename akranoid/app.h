#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "constants.h"
#include "GameScene.h"
#include "Menu.h"
#include"LoseScreen.h"
#include "Options.h"
#include "SoundHandler.h"
#include <iostream>
using namespace sf; 
#pragma once

struct app
{
	Menu* MainMenu;
	Options* options;
	GameScene* game;
	LoseScene* ResultScene;
	RenderWindow* window;
	SoundManager* MySoundManager;
	SceneManager* sm;
	app();
	~app();
	void run();

};
