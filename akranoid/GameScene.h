#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "constants.h"
#include "Ball.h"
#include "paddle.h"
#include "Brick.h"
#include "Menu.h"
#include "HUD.h"
#include "Options.h"
#include "SoundHandler.h"
#include "LevelGenerator.h"
#include <iostream>
#include <ctime>
#include <random>
using namespace sf;

struct GameScene: Scene
{
	
	Ball* ball = nullptr;
	Paddle* paddle = nullptr;
	Brick* bricks;
	int BrickAmount;
	HUD* hud;
	int health = 0;
	bool tilehit = false;
	float BallVelocity;
	RenderWindow* window;
	SoundManager* MySoundManager;
	Brick* (*lvls[3])(Brick* bricks, int& BrickAmount);
	SceneManager* sm;
	Options* options;
	GameScene(RenderWindow* _window, SceneManager* _sm, SoundManager* MySound, Options* _options);
	~GameScene();
	template <class T1, class T2> bool isColliding(T1& obj1, T2& obj2);
	bool Collision(Ball* ball, Paddle* paddle);
	bool Collision(Ball* ball, Brick& brick);

	Brick* DeleteBrick(Brick* bricks, int& BrickAmount);

	void Scene::draw()
	{
		BallVelocity = options->GetCurrentSpeed();
		ball = new Ball(GameFieldWidth / 2, GameFieldHeight / 2, BallVelocity);
		paddle = new Paddle(GameFieldWidth / 2, GameFieldHeight - 40);
		health = 3;
		bricks = lvls[rand() % 3](bricks, BrickAmount);
		while (health > 0)
		{
			window->clear(Color::Black);
			hud->Draw_hud(window,health);
			if (hud->pause)
			{
				ball->ResetPosition(paddle);
				hud->DrawPause(window);
				BallVelocity = options->GetCurrentSpeed();
			}

			else
			{
				hud->pause = false;
				ball->update();
				ball->wallCollision(BallVelocity);
				if (Collision(ball, paddle))
				{
					if (hud->Max_combo < hud->combo)	hud->Max_combo = hud->combo;
					hud->combo = 0;
					MySoundManager->PlaySound_Hit();
					if (BrickAmount == 0)
					{
						bricks = (*lvls[rand() % 3])(bricks, BrickAmount);
						
					}
				}
			}
			
			if (ball->isOut())
			{
				hud->pause = true;
				health--;
			}
				
			paddle->update();
			window->draw(ball->shape);
			window->draw(paddle->shape);
			for (int i = 0; i < BrickAmount; i++) window->draw(bricks[i].shape);
			for (int i = 0; i < BrickAmount&& !tilehit; i++)
			{
				if (Collision(ball, bricks[i]))
				{
					hud->score += options->score_per_hit[options->selected_item] + hud->combo * 0.25;
					bricks = DeleteBrick(bricks, BrickAmount);
					tilehit = true;
					hud->combo++;
					hud->combo_display.setColor(Color(rand() % 226+30, rand() % 226 + 30, rand() % 226 + 30));
					break;
				}
			}
			tilehit = false;
			input();
			window->display();
			
		}
		delete ball;
		delete paddle;
		if (hud->score > hud->Max_score)
		{
			hud->Max_score = hud->score;
			hud->Encrypt_And_Save(hud->Max_score);
		}
		MySoundManager->PlaySound_Lose();
		sm->SetActive("Results");
		
	}
	void Scene::input()
	{
		
		
	}
};

template<class T1, class T2>
inline bool GameScene::isColliding(T1& obj1, T2& obj2)
{
	return obj1.right() >= obj2.left()
		&& obj1.left() <= obj2.right()
		&&
		obj1.bottom() >= obj2.top() &&
		obj1.top() <= obj2.bottom();
}
