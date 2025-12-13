#include "GameManager.h"
#include "Deck.h"
#include "Player.h"
#include "RenderText.h"
#include "Computer.h"
#include "Utils.h"

GameManager* GameManager::_Instance = nullptr;

// Gets instance of the game manager
GameManager* GameManager::GetInstance()
{
    if (_Instance == nullptr)
    {
        _Instance = new GameManager();
    }
    return _Instance;
}

// Creates deck, player, renderer and computer
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
    Card* lastPlaced = nullptr;
    bool skipTurn = false;
    bool gameOver = false;

    // Loops until someone wins game
    do
    {
        _renderer->PlayerTurnRender(false, _player->GetCardsInHand(), _computer->GetCardsInHand(), _deck); // hasnt played

        // Players turn if not skipped
        if (!skipTurn)
        {
            lastPlaced = _player->PlayerTurn();

            // Checks if player won game
            if (_player->CheckWin())
            {
                // Finishes and quits game
                gameOver = true;
                _renderer->ShowResult(true);
                return;
            }
        }
        skipTurn = false;

        // Checks for special moves
        if (lastPlaced)
        {
            if (lastPlaced->GetSymbol() == "S") // Skips
            {
                skipTurn = true;
            }
            else if (lastPlaced->GetSymbol() == "+2") // +2
            {
                _computer->PickupCard();
                _computer->PickupCard();
                skipTurn = true;
            }
            else if (lastPlaced->GetSymbol() == "W") // Wild card
            {
                _player->ChooseWildColor();
            }
            // Removes last placed
            lastPlaced = nullptr;
        }

        _renderer->PlayerTurnRender(true, _player->GetCardsInHand(), _computer->GetCardsInHand(), _deck); // has played

        WAIT_FOR_INPUT;

        _renderer->OpponentTurnRender(false, _computer->GetCardsInHand(), _deck);

        WAIT_FOR_INPUT;

        // Computers turn if not skipped
        if (!skipTurn)
        {
            lastPlaced = _computer->MoveAction();

            // Checks if computer won game
            if (_computer->CheckWin())
            {
                _renderer->ShowResult(false);
                return;
            }
        }
        skipTurn = false;

        // Checks for special cards
        if (lastPlaced)
        {
            if (lastPlaced->GetSymbol() == "S") // Skip
            {
                skipTurn = true;
            }
            else if (lastPlaced->GetSymbol() == "+2") // +2
            {
                _player->PickupCard();
                _player->PickupCard();
                skipTurn = true;
            }
            else if (lastPlaced->GetSymbol() == "W") // Wildcard
            {
                _computer->ChooseWildColor();
            }
            lastPlaced = nullptr;
        }

        _renderer->OpponentTurnRender(true, _computer->GetCardsInHand(), _deck);

        WAIT_FOR_INPUT;

    } while (!gameOver);
}

