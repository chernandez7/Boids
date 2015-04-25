// This file acts as the main for our boids project. Here, we utilize the SFML
// library, import boids and flock classes, and run the program.
//#include <iostream>
#include <vector>
#include "Boid.h"
#include "Pvector.h"
#include "Flock.h"
#include "SFML\Window.hpp"
#include "SFML/Graphics.hpp"


using namespace std;

int main()
{
	int width = 600, length = 600;
	//Need to initialize window (Size can be changed later)
	sf::RenderWindow window(sf::VideoMode(length, width), "Boids", sf::Style::Default);
	window.setMouseCursorVisible(true);
	window.setKeyRepeatEnabled(true);


	//Create flock and boids
	Flock flock;

	//100 boids as a test
	for (int i = 0; i < 100; i++)
	{
		Boid b(rand() % length + 1, rand() % width + 1); //X and Y coordinate are half of window size (To start in the middle)
		flock.addBoid(b);
		//sf::CircleShape boid(length / 2, width / 2);
		sf::CircleShape boid(rand() % length + 1, rand() % width + 1 );
		boid.setFillColor(sf::Color(255,255,255));
		boid.setPointCount(3);
		boid.setRadius(10);
		window.draw(boid);
	}

	while (window.isOpen())
	{
		window.clear(sf::Color::Black);

		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//check for mouse click, draws and adds boid to flock if so.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mouseCoords = sf::Mouse::getPosition();
			Boid b(mouseCoords.x, mouseCoords.y);
			flock.addBoid(b);
			sf::CircleShape boid(mouseCoords.x, mouseCoords.y);
			boid.setFillColor(sf::Color(255, 255, 255));
			boid.setPointCount(3);
			boid.setRadius(10);
			window.draw(boid);
		}
		//While window is open apply 3 rules to each boid in vector<boid>
		/*
		for (int i = 0; i < flock.getSize(); i++)
		{
			flock[i].update();
		}
		*/
		window.display();
	}
	return 0;

}

/* 
Part of SFML Test 
sf::CircleShape shape(100.f);
sf::CircleShape shapestshape(155.f);
shapestshape.setFillColor(sf::Color::Blue);
shape.setFillColor(sf::Color::Green);
while (window.isOpen())
{
sf::Event event;
while (window.pollEvent(event))
{
if (event.type == sf::Event::Closed)
window.close();
}


window.clear();
// Objects are layered in the order that they were called.
// Here, shapestshape will appear in front of shape
window.draw(shape);
window.draw(shapestshape);
window.display();
}
*/