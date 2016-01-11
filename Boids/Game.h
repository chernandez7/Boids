#include "Flock.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#ifndef GAME_H
#define GAME_H

// Game handles the instantiation of a flock of boids, game input, asks the
// model to compute the next step in the stimulation, and handles all of the
// program's interaction with SFML. 

class Game {
private:
	sf::RenderWindow window;
	int window_width;
	int window_height;

	Flock flock;
	float boidsSize;
	vector<sf::CircleShape> shapes;

	void Render(sf::Text text, float fps, sf::Text text2, sf::Text text3, sf::Text text4, 
				sf::Text text5, sf::Text text6, sf::Text text7, sf::Text text8, sf::Text text9, sf::Text text10);
	void createBoid(float x, float y, bool predStatus, sf::Color fillColor, sf::Color outlineColor);
	void HandleInput();

public:
	Game();
	void Run();
};

#endif
