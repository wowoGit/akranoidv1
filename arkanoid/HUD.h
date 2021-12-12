#pragma once
#pragma warning(disable:4996)
#include <SFML/Graphics.hpp>
#include <time.h>
#include "constants.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace sf;

struct HUD
{
	bool pause = true;
	int score = 0;
	int combo = 0;
	int Max_score;
	int Max_combo = 0;
	Image map_image;
	Image heart_image;
	
	Texture map;
	Texture heart;
	Sprite s_map;
	Sprite s_heart;

	Font font;				
	Text text[HUD_ELEMENTS];
	Text score_display;
	Text combo_display;
	Text pause_text;
	HUD();
	void Encrypt_And_Save(int highest_score);
	int Decrypt_And_Read();
	void Draw_hud(RenderWindow* window, const int& health);
	void DrawPause(RenderWindow* window);
};