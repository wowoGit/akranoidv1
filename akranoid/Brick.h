#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "constants.h"
using namespace sf;

struct Brick
{
	RectangleShape shape;
	bool isdestroyed = false;
	void SetBrick(float x, float y);

	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();
};