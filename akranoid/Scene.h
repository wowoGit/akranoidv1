#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "constants.h"
#include "SoundHandler.h"
using namespace sf;


struct Scene
{

	virtual void draw() = 0;
	virtual void input() = 0;
};