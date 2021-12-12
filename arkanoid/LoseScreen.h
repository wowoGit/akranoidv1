#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "constants.h"
#include <string>
#include "SoundHandler.h"
#include "Scene.h"
#include "SceneManager.h"
#include "GameScene.h"
using namespace sf;

struct LoseScene : Scene
{
	bool active = true;
	Font font;
	Text Header;
	Text Result_Score;
	Text Highest_Score;
	Text Highest_Combo;
	Text Text_to_Continue;
	RenderWindow* window = nullptr;
	SceneManager* sm = nullptr;
	SoundManager* MySoundManager = nullptr;
	GameScene* game = nullptr;
	LoseScene(RenderWindow* _window, SceneManager* _sm, SoundManager* MySound, GameScene* _game);

	void Scene::draw()
	{
		Result_Score.setString("Result Score: " + std::to_string(game->hud->score));
		Highest_Score.setString("Highest Score: " + std::to_string(game->hud->Max_score));
		Highest_Combo.setString("Highest combo: " + std::to_string(game->hud->Max_combo));
		active = true;
		while (active)
		{
			window->clear(Color::Black);
			window->draw(Header);
			window->draw(Result_Score);
			window->draw(Highest_Combo);
			window->draw(Text_to_Continue);
			window->draw(Highest_Score);
			input();
			window->display();
		}

	}

	void Scene::input()
	{
		Event event;
		window->pollEvent(event);
		if (event.type == Event::KeyReleased)
		{
			if (event.key.code == Keyboard::Return)
			{
				sm->SetActive("Menu");
				MySoundManager->PlaySound_Button();
				active = false;
			}

		}
	}
};