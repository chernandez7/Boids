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
	sf::RenderWindow window(sf::VideoMode(length, width, 1000), "Boids", sf::Style::Default);
	window.setMouseCursorVisible(true);
	window.setKeyRepeatEnabled(true);
	//window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);



	//Create flock and boids
	Flock flock;
	vector<sf::CircleShape> shapes;


	//100 boids as a test
	for (int i = 0; i < 100; i++)
	{
		//	Boid b(rand() % length , rand() % width ); //X and Y coordinate are half of window size (To start in the middle)
		Boid b(length / 2, width / 2);
		flock.addBoid(b);
		sf::CircleShape shape(length / 2, width / 2);
		shape.setOutlineColor(sf::Color(255,0,0));
		shape.setFillColor(sf::Color(255, 0, 0));
		shape.setPointCount(3);
		shape.setRadius(10);
		shapes.push_back(shape);
	}

	while (window.isOpen())
	{
		//	window.clear(sf::Color::Black);

		

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
			sf::CircleShape shape(mouseCoords.x, mouseCoords.y);
			shape.setFillColor(sf::Color(255, 255, 255));
			shape.setPointCount(3);
			shape.setRadius(30);
			shapes.push_back(shape);
			window.draw(shapes[shapes.size()-1]);
		}

		window.clear();

		for (int i = 0; i < shapes.size(); i++)
		{
			window.draw(shapes[i]);
			cout << "(" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
			shapes[i].move(rand()%100, rand()%100);

		}

		flock.flocking();

		window.display();
	}
	return 0;

}

	/* Test with manipulation of basic shapes
	sf::RenderWindow window(sf::VideoMode(600,480,2000), "test", sf::Style::Default);

	sf::CircleShape circle(100);
	circle.setFillColor(sf::Color::Green);
	//.setRadius(5);
	circle.setOrigin(50,50);
	circle.setPointCount(4);
	//window.draw(circle);


	while (window.isOpen())
	{	

	sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		cout << circle.getPosition().x << ", " << circle.getPosition().y << endl;
		circle.move(.5,.5);
		//circle.scale(2, 2);
		circle.rotate(5);

		window.clear();
		window.draw(circle);

	
		window.display();
	}
	



	return 0;
}
*/