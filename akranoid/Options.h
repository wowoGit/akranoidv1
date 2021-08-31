#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "constants.h"
#include <string>
#include "Scene.h"
#include "SoundHandler.h"
#include "SceneManager.h"
using namespace sf;

struct Options: Scene
{
	SoundManager* MySoundManager = nullptr;
	RenderWindow* window = nullptr;
	SceneManager* sm = nullptr;
	Font font;
	Text Header;
	Text Music_Flag;
	bool music_status = false;
	bool active = false;
	Text parameters[CHANGABLE_PARAMETERS];
	Text speed_options[SPEED_TYPES];
	const double speed[SPEED_TYPES]{10.0f,12.0f,14.0f};
	const int score_per_hit[SPEED_TYPES]{ 3,4,5 };
	int selected_item = 0;
	double BallVelocity = 0;
	CircleShape Level_Indicators[SPEED_TYPES];
	Options(RenderWindow* _window, SceneManager* _sm, SoundManager* MySound);

	
	void MoveUp();
	void MusicOff(SoundManager* sound);
	void MusicOn(SoundManager* sound);
	
	void MoveDown();
	double GetCurrentSpeed();
	int GetPressedItem();
	void Scene::draw()
	{
		active = true;
		while (active)
		{
			window->clear(Color::Black);
			for (int i = 0; i < SPEED_TYPES; i++)
			{
				window->draw(Header);
				window->draw(speed_options[i]);
				window->draw(Level_Indicators[i]);
				window->draw(Music_Flag);
			}
			for (int i = 0; i < CHANGABLE_PARAMETERS; i++)
			{
				window->draw(parameters[i]);
			}
			input();
			window->display();
		}
	}
	void Scene::input()
	{
		Event event;
			while (window->pollEvent(event))
			{
				switch (event.type)
				{

				case Event::KeyReleased:
					switch (event.key.code)
					{
					case Keyboard::Up:
						MySoundManager->PlaySound_Button();
						MoveUp();
						break;
					case Keyboard::Down:
						MySoundManager->PlaySound_Button();
						MoveDown();
						break;
					case Keyboard::Right:
						MySoundManager->PlaySound_Button();
						music_status = false;
						MusicOff(MySoundManager);
						break;
					case Keyboard::Left:
						MySoundManager->PlaySound_Button();
						music_status = true;
						MusicOn(MySoundManager);
						break;
					case Keyboard::Return:
						MySoundManager->PlaySound_Button();
						switch (GetPressedItem())
						{
						case 0:
							BallVelocity = speed[0];
							break;
						case 1:
							BallVelocity = speed[1];
							break;
						case 2:
							BallVelocity = speed[2];
							break;
						}
						sm->SetActive("Menu");
						active = false;
						break;
					case Keyboard::Escape:
						MySoundManager->PlaySound_Button();
						sm->SetActive("Menu");
						active = false;
						break;
					}
				}

			}
		
		
	}
	
};