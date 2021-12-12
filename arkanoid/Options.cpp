#include "Options.h"

Options::Options(RenderWindow* _window, SceneManager* _sm, SoundManager* MySound)
{
	window = _window;
	MySoundManager = MySound;
	sm = _sm;
	Level_Indicators[0].setRadius(10);
	Level_Indicators[0].setOutlineColor(Color::Yellow);
	Level_Indicators[0].setFillColor(Color::Red);
	Level_Indicators[0].setPosition(50, 195);
	Level_Indicators[0].setOutlineThickness(3.0f);

	Level_Indicators[1].setRadius(10);
	Level_Indicators[1].setOutlineColor(Color::Yellow);
	Level_Indicators[1].setFillColor(Color::Black);
	Level_Indicators[1].setPosition(50, 295);
	Level_Indicators[1].setOutlineThickness(3.0f);

	Level_Indicators[2].setRadius(10);
	Level_Indicators[2].setOutlineColor(Color::Yellow);
	Level_Indicators[2].setFillColor(Color::Black);
	Level_Indicators[2].setPosition(50, 395);
	Level_Indicators[2].setOutlineThickness(3.0f);


	font.loadFromFile("PressStart2P-vaV7.ttf");


	Header.setCharacterSize(30);
	Header.setFillColor(Color::Red);
	Header.setPosition(450, 50);
	Header.setFont(font);
	Header.setString("OPTIONS");

	parameters[0].setCharacterSize(25);
	parameters[0].setFillColor(Color::Red);
	parameters[0].setPosition(50, 100);
	parameters[0].setFont(font);
	parameters[0].setString("Change speed:");

	parameters[1].setCharacterSize(25);
	parameters[1].setFillColor(Color::Red);
	parameters[1].setPosition(600, 100);
	parameters[1].setFont(font);
	parameters[1].setString("Music:");

	Music_Flag.setCharacterSize(20);
	Music_Flag.setFillColor(Color::Red);
	Music_Flag.setPosition(750, 103);
	Music_Flag.setFont(font);
	Music_Flag.setString("OFF");


	speed_options[0].setCharacterSize(15);
	speed_options[0].setFillColor(Color::Yellow);
	speed_options[0].setPosition(100, 200);
	speed_options[0].setFont(font);
	speed_options[0].setString("Casual");

	speed_options[1].setCharacterSize(15);
	speed_options[1].setFillColor(Color::Yellow);
	speed_options[1].setPosition(100, 300);
	speed_options[1].setFont(font);
	speed_options[1].setString("Hardcore");

	speed_options[2].setCharacterSize(15);
	speed_options[2].setFillColor(Color::Yellow);
	speed_options[2].setPosition(100, 400);
	speed_options[2].setFont(font);
	speed_options[2].setString("MADNESS");
}

void Options::MoveUp()
{
	if (selected_item - 1 >= 0)
	{
		Level_Indicators[selected_item].setFillColor(Color::Black);
		selected_item--;
		Level_Indicators[selected_item].setFillColor(Color::Red);

	}
}

void Options::MusicOff(SoundManager* sound)
{
	sound->PlayMusic(music_status);
	Music_Flag.setString("OFF");
	Music_Flag.setFillColor(Color::Red);

}

void Options::MusicOn(SoundManager* sound)
{
	sound->PlayMusic(music_status);
	Music_Flag.setString("ON");
	Music_Flag.setFillColor(Color::Green);
}

void Options::MoveDown()
{

	if (selected_item + 1 < 3)
	{
		Level_Indicators[selected_item].setFillColor(Color::Black);
		selected_item++;
		Level_Indicators[selected_item].setFillColor(Color::Red);

	}
}

int Options::GetPressedItem()
{
	return selected_item;
}

double Options::GetCurrentSpeed()
{
	return speed[selected_item];
}
