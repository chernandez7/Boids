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
// library, import boids and flock classes, and run the program.-
*/
sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

const int window_height = desktop.height;
const int window_width = desktop.width;

int main()
{
	/*
	//Debugging for Pvector properties
	Pvector test(0, 0);
	Pvector test2(2, 2);
	test.addVector(test2);
	test.set(7, 7); 
	Boid testt(3,2);
	testt.location.addVector(test);
	testt.acceleration.divScalar(5);
	*/
	


	sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Boids", sf::Style::None);


	//int width = 600, length = 600;
	//Need to initialize window (600 width and length, 100 bytes per pixel)
	//sf::RenderWindow window(sf::VideoMode(), "Boids", sf::Style::Fullscreen);
	window.setMouseCursorVisible(true);
	window.setKeyRepeatEnabled(true);
	//window.setFramerateLimit(60);
	//window.setVerticalSyncEnabled(true);

	//Create flock, vector of shapes, and initialize boids
	Flock flock;
	vector<sf::CircleShape> shapes;




	//100 boids as a test
	for (int i = 0; i < 100; i++)
	{
		Boid b(rand()%window_width,rand()%window_height);
		//Boid b(window_width / 2, window_height / 2);

		//Boid *b = new Boid(x, y);
		sf::CircleShape shape(10,3);
		shape.setOutlineColor(sf::Color(255,0,0));
		shape.setFillColor(sf::Color::Green);
		shape.setOutlineColor(sf::Color::White);
		shape.setOutlineThickness(1);
		//shape.setFillColor(sf::Color(255, 0, 0));
		//shape.setPointCount(3);
		shape.setRadius(5);
		shape.setPosition(b.location.x, b.location.y);
		//shape.setPosition(window_width / 2, window_height / 2);
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
			if ((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X))
				
				window.close();
		}

		//check for mouse click, draws and adds boid to flock if so.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
			Boid b(mouseCoords.x, mouseCoords.y);
			sf::CircleShape shape(10,3);
			shape.setPosition(mouseCoords.x, mouseCoords.y);
			shape.setOutlineColor(sf::Color(255, 0, 0));
			shape.setFillColor(sf::Color(255, 0, 0));
			shape.setOutlineColor(sf::Color::White);
			shape.setOutlineThickness(1);
			shape.setRadius(5);
			//shape.setPosition(length / 2, width / 2);
			flock.addBoid(b);
			shapes.push_back(shape);
			//shapes[shapes.size()-1].rotate(shapes[shapes.size()-1].getPosition().y - shapes[shapes.size()-1].getPosition().x); //Rotates triangles to start off pointing where they are going
			window.draw(shapes[shapes.size()-1]);
		}

		//Clears previous frams of visualization to not have clutter.
		window.clear();

		//Draws all of the Boids out, prints code location and location in window
		for (int i = 0; i < shapes.size(); i++)
		{
			window.draw(shapes[i]);
			//cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
			//cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;
			//shapes[i].move(rand()%200-100, rand()%200-100);
			//shapes[i].move(rand()%25, rand()%25);

			shapes[i].setPosition(flock.getBoid(i).location.x, flock.getBoid(i).location.y);

			float theta;
			theta = flock.getBoid(i).angle(flock.getBoid(i).velocity);
			shapes[i].setRotation(theta);
			

			//flock.getBoid(i).location.set(shapes[i].getPosition().x, shapes[i].getPosition().y);
			/*Either set shape to object or vice versa*/
			

			
			//SFML a brute force way of wrapping around
			if (shapes[i].getPosition().x >window_width || shapes[i].getPosition().x <0 || shapes[i].getPosition().y > window_height || shapes[i].getPosition().y < 0)
			{
				if (shapes[i].getPosition().x >window_width)
				{
					shapes[i].setPosition(shapes[i].getPosition().x - window_width, shapes[i].getPosition().y);
				}
				if (shapes[i].getPosition().y > window_height)
				{
					shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y - window_height);
				}
				if (shapes[i].getPosition().x <0)
				{
					shapes[i].setPosition(shapes[i].getPosition().x + window_width, shapes[i].getPosition().y);
				}
				if (shapes[i].getPosition().y < 0)
				{
					shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y + window_height);
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