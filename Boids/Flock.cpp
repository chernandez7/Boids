#include "Boid.h"
#include "Flock.h"
#include "SFML/Graphics.hpp"

// =============================================== //
// ======== Flock Functions from Flock.h ========= //
// =============================================== //

int Flock::getSize()
{
	return flock.size();
}

Boid Flock::getBoid(int i) { return flock[i]; }


void Flock::addBoid(Boid b) { flock.push_back(b); }

// Runs the run function for every boid in the flock checking against the flock
// itself. Which in turn applies all the rules to the flock.
void Flock::flocking()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].run(flock);
		//collisionChecker(flock[i], shapes);
	}
}

int Flock::preyCount()
{
	int count = 0;
	for (int i = 0; i < flock.size(); i++)
	{
		if (!flock[i].predatorStatus)
			count++;
	}
	return count;
}

int Flock::predCount()
{
	return flock.size() - preyCount();
}

/* Checking and deleting boids when colliding with predators increases
* time complexity way too much to the point where it hurts performance immensely!

void Flock::collisionChecker(Boid b, vector<sf::CircleShape> shapes)
{
	if (!b.predatorStatus)
	{
		for (int i = 0; i < flock.size(); i++)
		{
			if (flock[i].predatorStatus == true && b.location.distance(flock[i].location) < abs(1))
			{
				int boidIndex = getBoidIndex(b);
				flock.erase(flock.begin() + (boidIndex - 1));
				shapes.erase(shapes.begin() + (boidIndex - 1));
			}
		}
	}
}


int Flock::getBoidIndex(Boid b)
{
	int count = 0;
	for (int i = 0; i < flock.size(); i++)
	{
		if (flock[i] == b)
		{
			return i;
		}
		count++;
	}
	return -1;
}
*/