#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "constants.h"
#include "Scene.h"
#include <string>
#include "SoundHandler.h"
using namespace sf;


struct SceneManager
{
    std::vector<std::pair<Scene*, std::string>> scenepull;
    Scene* currentScene = 0;

    void AddScene(Scene* sceneptr, std::string name);
    void SetActive(std::string name);
    void draw();
};
