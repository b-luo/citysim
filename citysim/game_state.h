#pragma once

#include "game.h"

class GameState {
public:
	Game *game;
	
	virtual void draw(const double dt) = 0;
	virtual void update(const double dt) = 0;
	virtual void handleInput() = 0;
};
