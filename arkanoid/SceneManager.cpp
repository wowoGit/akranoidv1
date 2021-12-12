#include "SceneManager.h"

void SceneManager::AddScene(Scene* sceneptr, std::string name)
{
	scenepull.push_back(std::make_pair(sceneptr, name));
}

void SceneManager::SetActive(std::string name)
{
    for (auto n : scenepull)
    {
        if (n.second == name)
        {
            currentScene = n.first;
        }
    }
}

void SceneManager::draw()
{
    currentScene->draw();
}
