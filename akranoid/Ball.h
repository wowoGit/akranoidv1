#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "constants.h"
#include "Menu.h"
#include "paddle.h"
#include <iostream>
using namespace sf;

struct Ball
{
	CircleShape shape;
	double BallVelocity = 0;
	Vector2f velocity{-BallVelocity, -BallVelocity};
	Ball(float x, float y, int BallVel);
	void update();
	void wallCollision(double ballVel);
	bool isOut();
	void ResetPosition(Paddle* paddle);
	float x();
	float y();
	float top();
	float bottom();
	float left();
	float right();
};