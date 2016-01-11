#include "Flock.h"

#include "Game.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#define BOID_AMOUNT 1

// Construct window using SFML
Game::Game()
{
	this->boidsSize = 5.0;
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	this->window_height = desktop.height;
	this->window_width = desktop.width;
	this->window.create(sf::VideoMode(window_width, window_height, desktop.bitsPerPixel), "Boids", sf::Style::None);
}

// Run the simulation. Run creates the boids that we'll display, checks for user
// input, and updates the view
void Game::Run()
{
	for (int i = 0; i < BOID_AMOUNT; i++) {

		createBoid(window_width / 2, window_height / 2, false, sf::Color::Green, sf::Color::Blue);
		
	}
	while (window.isOpen()) {
		HandleInput();
		Render();
	}
}

void Game::HandleInput()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		// "close requested" event: we close the window
		// Implemented alternate ways to close the window. (Pressing the escape, X, and BackSpace key also close the program.)
		if ((event.type == sf::Event::Closed) ||
			(event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Escape) ||
			(event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::BackSpace) ||
			(event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::X))
		{
			window.close();
		}

		// Event to create new "prey" boids
		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Space) {
			//createBoid(window_width / 2, window_height / 2, false, sf::Color::Green, sf::Color::Blue);
			createBoid(rand() % window_width, rand() % window_height, false, sf::Color::Green, sf::Color::Blue);
		}
	}

	// Check for mouse click, draws and adds boid to flock if so.
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		// Gets mouse coordinates, sets that as the location of the boid and the shape
		sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
		createBoid(mouseCoords.x, mouseCoords.y, true, sf::Color::Red, sf::Color::Red);

	}


}

void Game::createBoid(float x, float y, bool predStatus, sf::Color fillColor, sf::Color outlineColor)
{
	Boid b(x, y, predStatus);
	sf::CircleShape shape(20, 3);
	shape.setPosition(x, y);
	shape.setFillColor(fillColor);
	shape.setOutlineColor(outlineColor);
	shape.setOutlineThickness(.5);
	shape.setRadius(boidsSize);

	flock.addBoid(b);
	shapes.push_back(shape);

	// New Shape is drawn
	window.draw(shapes[shapes.size() - 1]);
}

void Game::Render()
{
	window.clear();

	// Draws all of the Boids out, and applies functions that are needed to update.
	for (int i = 0; i < shapes.size(); i++) {
		window.draw(shapes[i]);

		//cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
		//cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;

		// Matches up the location of the shape to the boid
		shapes[i].setPosition(flock.getBoid(i).location.x, flock.getBoid(i).location.y);

		// Calculates the angle where the velocity is pointing so that the triangle turns towards it.
		float theta = flock.getBoid(i).angle(flock.getBoid(i).velocity);
		shapes[i].setRotation(theta);

		// Prevent boids from moving off the screen through wrapping
		// If boid exits right boundary
		if (shapes[i].getPosition().x > window_width)
			shapes[i].setPosition(shapes[i].getPosition().x - window_width, shapes[i].getPosition().y);
		// If boid exits bottom boundary
		if (shapes[i].getPosition().y > window_height)
			shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y - window_height);
		// If boid exits left boundary
		if (shapes[i].getPosition().x < 0)
			shapes[i].setPosition(shapes[i].getPosition().x + window_width, shapes[i].getPosition().y);
		// If boid exits top boundary
		if (shapes[i].getPosition().y < 0)
			shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y + window_height);
	}

	// Applies the three rules to each boid in the flock and changes them accordingly.
	flock.flocking();

	window.display();
}
