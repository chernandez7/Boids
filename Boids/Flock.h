// This file contains the class needed to create flock of boids. It utilizes
// the boids class and initializes boid flocks with parameters that can be 
// specified. This class will be utilized in main.
#include <iostream>
#include <vector>
#include "Boid.h"

using namespace std;

#ifndef FLOCK_H_
#define FLOCK_H_

// Possible: struct instead? template?
class Flock
{
private:

public:
	vector<Boid> flock;

	Flock()
	{
		//vector<Boid> flock;
	}

	Flock::~Flock()
	{
		/*
		delete flock;
		*/
	}

	//add function
	void addBoid(Boid b);
	int getSize();
	void flocking();
	Boid getBoid(int i);
};

#endif