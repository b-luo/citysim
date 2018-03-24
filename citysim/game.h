#pragma once

#include <stack>
#include <SFML/Graphics.hpp>

class GameState;

// State manager
class Game {
public:
	std::stack<GameState *> states;
	sf::RenderWindow window;

	Game();
	~Game();

	// State related operations
	void pushState(GameState *);
	void popState();
	void changeState(GameState *);
	GameState *peekState();

	void gameLoop();
};
