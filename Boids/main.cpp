// This file acts as the main for our boids project. Here, we utilize the SFML
// library, import boids and flock classes, and run the program.
//#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <Boid.h>
#include <Pvector.h>
//          Flock
//			Pvector
using namespace std;

int main()
{
    /*sf::RenderWindow window(sf::VideoMode(400, 400), "TITLE FOR WINDOW");
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
    }*/
    return 0; 
}
