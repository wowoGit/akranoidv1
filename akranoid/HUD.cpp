#include "HUD.h"

HUD::HUD()
{
	Max_score = Decrypt_And_Read();
	font.loadFromFile("PressStart2P-vaV7.ttf");
	map_image.loadFromFile("field.png");
	map.loadFromImage(map_image);
	s_map.setTexture(map);
	heart_image.loadFromFile("heart.png");
	heart.loadFromImage(heart_image);
	s_heart.setTexture(heart);

	text[0].setCharacterSize(15);
	text[0].setFillColor(Color::Red);
	text[0].setPosition(GameFieldWidth + 20, 250);
	text[0].setFont(font);
	text[0].setString("LIVES:");

	text[1].setCharacterSize(15);
	text[1].setFillColor(Color::Red);
	text[1].setPosition(GameFieldWidth + 20, GameFieldHeight / 1.5);
	text[1].setFont(font);
	text[1].setString("SCORE:");

	score_display.setCharacterSize(15);
	score_display.setFillColor(Color::Red);
	score_display.setPosition(GameFieldWidth + 110, GameFieldHeight / 1.5);
	score_display.setFont(font);

	pause_text.setString("Press Space to start!");
	pause_text.setCharacterSize(30);
	pause_text.setFillColor(Color::Red);
	pause_text.setPosition(GameFieldWidth / 6.5, GameFieldHeight / 1.5);
	pause_text.setFont(font);

	combo_display.setString("Combo");
	combo_display.setCharacterSize(15);
	combo_display.setFillColor(Color::Red);
	combo_display.setPosition(GameFieldWidth + 20, GameFieldHeight / 1.2);
	combo_display.setFont(font);

}

void HUD::Encrypt_And_Save(int highest_score)
{
	FILE* fileptr = fopen("results.bin", "wb");
	int converted = ~highest_score;
	converted = converted << 3;
	fwrite(&converted, sizeof(int), 1, fileptr);
	fclose(fileptr);
}

int HUD::Decrypt_And_Read()
{
	FILE* fileptr = fopen("results.bin", "rb");
	int score = 0;
	fread(&score, sizeof(int), 1, fileptr);
	score = score >> 3;
	score = ~score;
	fclose(fileptr);
	return score;
}

void HUD::Draw_hud(RenderWindow* window, const int& health)
{

	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (i == 0 || i == 59)
			{
				s_map.setPosition(j * 10, i * 10);
				window->draw(s_map);
			}
			else if (j == 0 || j == 79)
			{
				s_map.setPosition(j * 10, i * 10);
				window->draw(s_map);
			}



		}
	}

	for (int i = 0; i < health; i++)
	{
		s_heart.setPosition(GameFieldWidth + 110 + i * 30, 240);
		window->draw(s_heart);
	}

	for (int i = 0; i < HUD_ELEMENTS; i++)
	{
		window->draw(text[i]);
	}
	score_display.setString(std::to_string(score));


	window->draw(score_display);
	if (combo >= 1)
	{
		combo_display.setString("Combo: " + std::to_string(combo) + "X");
		combo_display.setCharacterSize(15 + combo * 0.25);
		window->draw(combo_display);
	}
}

void HUD::DrawPause(RenderWindow* window)
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
		pause = false;
	window->draw(pause_text);
}
