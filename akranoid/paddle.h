#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "constants.h"
using namespace sf;

struct Paddle
{
	RectangleShape shape;
	Vector2f velocity;
	Texture padtexture;
	Paddle(float x, float y);
	void update();
	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();
};