#include "Boid.h"
#include "Flock.h"

using namespace std;

// =============================================== //
// ======== Flock Functions from Flock.h ========= //
// =============================================== //

//Returns the size of the vector<Boid>
int Flock::getSize()
{
	return flock.size();
}

//Returns the Boid of the ith element in vector<Boid>
Boid Flock::getBoid(int i)
{
	return flock[i];
}

//Adds a boid to the end of the vector<Boid>
void Flock::addBoid(Boid b)
{
	flock.push_back(b);
}

//Runs the run function for every boid in the flock checking against the flock
//itself. Which in turn applies all the rules to the flock.
void Flock::flocking() 
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].run(flock);
	}
}