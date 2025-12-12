#include "GameManager.h"
#include "Deck.h"
#include "Player.h"
#include "RenderText.h"
#include "Computer.h"

GameManager* GameManager::_Instance = nullptr;

GameManager* GameManager::GetInstance()
{
    if (_Instance == nullptr)
    {
        _Instance = new GameManager();
    }
    return _Instance;
}

// Creates deck, player and computer
void GameManager::StartGame()
{
    _deck = new Deck();
    _renderer = new RenderText();
    _player = new Player(_deck, _renderer);
    _computer = new Computer(_deck, _renderer);
    PlayGame();
}

// Plays the game
void GameManager::PlayGame()
{
    bool gameOver = false;

    // Loops until someone wins game
    do
    {
        _player->PlayerTurn();

        // Checks if player won game
        if (_player->CheckWin())
        {
            gameOver = true;
            WinGame();
        }
        Card* lastPlaced = _computer->MoveAction();

        // Checks if computer won game
        if (_computer->CheckWin())
        {
            LoseGame();
        }
    } while (!gameOver);
}

void GameManager::WinGame()
{
}

void GameManager::LoseGame()
{
}

