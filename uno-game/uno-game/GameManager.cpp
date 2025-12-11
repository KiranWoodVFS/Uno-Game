#include "GameManager.h"

GameManager* GameManager::sInstance = nullptr;

GameManager* GameManager::GetInstance()
{
    if (sInstance == nullptr)
    {
        sInstance = new GameManager();
    }
    return sInstance;
}

//GameManager::GameManager()
//{
//}
//
//GameManager::~GameManager()
//{
//}
//
//void GameManager::Run()
//{
//
//}