#pragma once

#include <SFML/Graphics.hpp> 

#include "game_state.h"
// Indicate we are in the main menu
class StartState : public GameState {
	sf::View view;
public:
	StartState(Game *game);

	virtual void draw(double timestep);
	virtual void update(double timestep);
	virtual void handleInput();
};