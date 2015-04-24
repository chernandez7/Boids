// This file contains the class needed to create flock of boids. It utilizes
// the boids class and initializes boid flocks with parameters that can be 
// specified. This class will be utilized in main.
#include <iostream>
#include <vector>
#include "Boid.h"
//#include <Flock.h>

using namespace std;

#ifndef FLOCK_H_
#define FLOCK_H_

// Possible: struct instead? template?
class Flock
{
private:
	vector<Boid> flock;

public:
	Flock()
	{
		//flock = new vector<Boid>();
	}

	//add function
	void addBoid(Boid b);

};

#endif FLOCK_H_