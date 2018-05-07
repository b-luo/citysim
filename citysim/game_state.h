#pragma once

#include "game.h"

class GameState {
public:
	Game *game;
	
	virtual void draw(double timestep) = 0;
	virtual void update(double timestep) = 0;
	virtual void handleInput() = 0;
};
