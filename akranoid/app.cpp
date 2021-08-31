#include "app.h"

app::app()
{
	window = new RenderWindow(VideoMode(WindowWidth, WindowHeight), "Arkanoid!");
	sm = new SceneManager();
	MySoundManager = new SoundManager;
	MainMenu = new Menu(window, sm, MySoundManager);
	options = new Options(window, sm, MySoundManager);
	game = new GameScene(window, sm, MySoundManager, options);
	ResultScene = new LoseScene(window, sm, MySoundManager, game);
	window->setFramerateLimit(60);
	sm->AddScene(MainMenu, "Menu");
	sm->AddScene(options, "Options");
	sm->AddScene(game, "Game");
	sm->AddScene(ResultScene, "Results");
	sm->SetActive("Menu");
}

app::~app()
{
	delete window, sm, MySoundManager, MainMenu, options, game, ResultScene;
}

void app::run()
{
	while (true)
	{
		sm->draw();
	}
}
