#include "Menu.h"

Menu::Menu(RenderWindow* _window, SceneManager* mysm, SoundManager* MySound)
{
	sm = mysm;
	MySoundManager = MySound;
	window = _window;
	font.loadFromFile("PressStart2P-vaV7.ttf");
	text[0].setCharacterSize(50);
	text[0].setFillColor(Color::Red);
	text[0].setPosition(GameFieldWidth / 2.5, GameFieldHeight / 3);
	text[0].setFont(font);
	text[0].setString("START GAME");

	text[1].setCharacterSize(30);
	text[1].setFillColor(Color::White);
	text[1].setPosition(450, GameFieldHeight / 2);
	text[1].setFont(font);
	text[1].setString("OPTIONS!");

	text[2].setCharacterSize(30);
	text[2].setFillColor(Color::White);
	text[2].setPosition(500, GameFieldHeight / 1.5);
	text[2].setFont(font);
	text[2].setString("QUIT");
}

void Menu::MoveUp()
{
	if (selected_item - 1 >= 0)
	{
		text[selected_item].setFillColor(Color::White);
		selected_item--;
		text[selected_item].setFillColor(Color::Red);

	}
}

void Menu::MoveDown()
{
	if (selected_item + 1 < 3)
	{
		text[selected_item].setFillColor(Color::White);
		selected_item++;
		text[selected_item].setFillColor(Color::Red);

	}
}

inline int Menu::GetPressedItem()
{
	return selected_item;
}
