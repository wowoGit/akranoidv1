#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "constants.h"
#include "Scene.h"
#include "SceneManager.h"
#include "SoundHandler.h"
using namespace sf;


struct Menu:Scene
{
	SoundManager* MySoundManager = 0;
	Font font;
	Text text[MENU_ELEMENTS];
	int selected_item = 0;
	SceneManager* sm = nullptr;
	RenderWindow* window = nullptr;
	bool active = false;
	Menu(RenderWindow* _window, SceneManager* mysm, SoundManager* MySound);
	void MoveUp();
	void MoveDown();
	inline int GetPressedItem();
	void Scene::draw()
	{
		active = true;
		while (active)
		{
			window->clear(Color::Black);
			for (int i = 0; i < MENU_ELEMENTS; i++)
			{
				window->draw(text[i]);
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
				{
				switch (event.key.code)
				{
				case Keyboard::Up:
					MoveUp();
					MySoundManager->PlaySound_Button();
					break;
				case Keyboard::Down:
					MoveDown();
					MySoundManager->PlaySound_Button();
					break;
				case Keyboard::Return:
					MySoundManager->PlaySound_Button();
					switch (GetPressedItem())
					{
					case 0:

						sm->SetActive("Game");
						active = false;
						break;
					case 1:
						sm->SetActive("Options");
						active = false;
						break;
					case 2:
						window->close();
						std::exit(0);
						break;
					}
					break;
				}
				}
			}
		}
	}
};
