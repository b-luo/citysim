#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.h"

Game::Game() {
	window.create(sf::VideoMode(800, 600), "City Simulation");
	window.setFramerateLimit(60);
}

Game::~Game() {
	while (!states.empty()) {
		popState();
	}
}

void Game::pushState(GameState *state) {
	states.push(state);
}

void Game::popState() {
	if (states.empty()) return;
	delete states.top();
	states.pop();
}

void Game::changeState(GameState *state) {
	if (!states.empty()) popState();
	pushState(state);
}

GameState *Game::peekState() {
	if (states.empty()) return nullptr;
	return states.top();
}

void Game::gameLoop() {
	sf::Clock clock;

	while (window.isOpen()) {
		sf::Time elapsed = clock.restart();
		double dt = elapsed.asSeconds();

		if (peekState() == nullptr) continue;
		GameState *currState = peekState();
		currState->handleInput();
		currState->update(dt);
		window.clear(sf::Color::Black);
		currState->draw(dt);
		window.display();
	}
}
