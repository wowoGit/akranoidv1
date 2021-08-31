#include "LoseScreen.h"

LoseScene::LoseScene(RenderWindow* _window, SceneManager* _sm, SoundManager* MySound, GameScene* _game)
{
	window = _window;
	sm = _sm;
	MySoundManager = MySound;
	game = _game;

	font.loadFromFile("PressStart2P-vaV7.ttf");

	Header.setFont(font);
	Header.setFillColor(Color::Green);
	Header.setPosition(400, 50);
	Header.setCharacterSize(30);
	Header.setString("RUN RESULTS");

	Result_Score.setFont(font);
	Result_Score.setFillColor(Color::Red);
	Result_Score.setPosition(100, 300);
	Result_Score.setCharacterSize(23);
	//Result_Score.setString("Result Score: " + game->hud->score);

	Highest_Score.setFont(font);
	Highest_Score.setFillColor(Color::Yellow);
	Highest_Score.setPosition(77, 200);
	Highest_Score.setCharacterSize(23);

	Highest_Combo.setFont(font);
	Highest_Combo.setFillColor(Color::Red);
	Highest_Combo.setPosition(77, 400);
	Highest_Combo.setCharacterSize(23);
	Highest_Combo.setString("Highest combo: ");

	Text_to_Continue.setFont(font);
	Text_to_Continue.setFillColor(Color::Green);
	Text_to_Continue.setPosition(200, WindowHeight - 100);
	Text_to_Continue.setCharacterSize(30);
	Text_to_Continue.setString("PRESS ENTER TO CONTINUE!");
}
