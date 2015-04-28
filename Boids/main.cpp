#include <iostream>
#include <vector>
#include "Boid.h"
#include "Pvector.h"
#include "Flock.h"
#include "SFML\Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;

/*
Breif description of Boid Class:
// This file acts as the main for our boids project. Here, we utilize the SFML
// library, import boids and flock classes, and run the program.
*/

int main()
{
	int width = 600, length = 600;
	//Need to initialize window (600 width and length, 100 bytes per pixel)
	sf::RenderWindow window(sf::VideoMode(length, width, 1000), "Boids", sf::Style::Default);
	window.setMouseCursorVisible(true);
	window.setKeyRepeatEnabled(true);
	//window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	//Create flock, vector of shapes, and initialize boids
	Flock flock;
	vector<sf::CircleShape> shapes;

	float x = length / 2;
	float y = width / 2;

	//100 boids as a test
	for (int i = 0; i < 10; i++)
	{
		Boid b(x,y);
		//Boid *b = new Boid(x, y);
		sf::CircleShape shape(10);
		shape.setOutlineColor(sf::Color(255,0,0));
		shape.setFillColor(sf::Color(255, 0, 0));
		shape.setPointCount(3);
		shape.setRadius(8);
		//shape.setPosition(length / 2, width / 2);
		flock.addBoid(b);
		shapes.push_back(shape);
	}

	while (window.isOpen())
	{	
		//Event used to close program when window is closed
		sf::Event event;
		while (window.pollEvent(event))
		{
			//"close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//check for mouse click, draws and adds boid to flock if so.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mouseCoords = sf::Mouse::getPosition();
			Boid b(mouseCoords.x, mouseCoords.y);
			sf::CircleShape shape(10);
			shape.setPosition(mouseCoords.x, mouseCoords.y);
			shape.setOutlineColor(sf::Color(255, 0, 0));
			shape.setFillColor(sf::Color(255, 0, 0));
			shape.setPointCount(3);
			shape.setRadius(8);
			//shape.setPosition(length / 2, width / 2);
			flock.addBoid(b);
			shapes.push_back(shape);
			window.draw(shapes[shapes.size()-1]);
		}

		//Clears previous frams of visualization to not have clutter.
		window.clear();

		//Draws all of the Boids out, prints code location and location in window
		for (int i = 0; i < shapes.size(); i++)
		{
			window.draw(shapes[i]);
			cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
			cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;
			shapes[i].move(rand()%100, rand()%100);
			//shapes[i].setPosition(flock.getBoid(i).location.x, flock.getBoid(i).location.y);
			
			//SFML brute force way of wrapping around
			if (shapes[i].getPosition().x >600 || shapes[i].getPosition().x <0 || shapes[i].getPosition().y >600 || shapes[i].getPosition().y < 0)
			{
				if (shapes[i].getPosition().x >600)
				{
					shapes[i].setPosition(shapes[i].getPosition().x - 600, shapes[i].getPosition().y);
				}
				if (shapes[i].getPosition().y > 600)
				{
					shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y-600);
				}
				if (shapes[i].getPosition().x <0)
				{
					shapes[i].setPosition(shapes[i].getPosition().x + 600, shapes[i].getPosition().y);
				}
				if (shapes[i].getPosition().y < 0)
				{
					shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y+600);
				}
			}


		}

		//Applies the three fules to each boid in the flock and changes them accordingly.
		flock.flocking();

		//Updates the window with current values of any data that was modified.
		window.display();

	//This loop continues until window is closed. Continues the process of updating, drawing, rendering the boids, and the window.
	}
	return 0;

}