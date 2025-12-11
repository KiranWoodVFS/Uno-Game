#pragma once

class GameManager
{
	// Calls the functions from other classes
	// manages if the game has been won

public:
	static GameManager* GetInstance();
	void Run();
private:
	static GameManager* sInstance;
};

