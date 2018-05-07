#pragma once

#include <SFML/Graphics.hpp>

#include "game_state.h"

class EditorState : public GameState {
	sf::View gameView, guiView;
public:
	EditorState(Game *game);
	virtual void draw(double timestep) = 0;
	virtual void update(double timestep) = 0;
	virtual void handleInput() = 0;
};