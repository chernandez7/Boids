#include "Pvector.h"
#include <vector>
#include <iostream>

using namespace std;

#ifndef BOID_H_
#define BOID_H_

/*
Breif description of Boid Class:
//The boid class creates an object which has multiple vectors (location, velocity, acceleration)
//Boids are given certain properties and rules to follow when interacting with other boids.
//They are being used to simulate flocking patterns and properties
*/

class Boid
{
public:

	//Public Variables
	Pvector location;
	Pvector velocity;
	Pvector acceleration;
	float maxSpeed;
	float maxForce;
	

	//Constructors
	Boid(){}

	Boid(float x, float y)
	{
		//Pvector* acceleration = new Pvector(0, 0);
		acceleration = Pvector(0, 0);
		//Pvector* velocity = new Pvector(0, 0);
		velocity = Pvector(rand()%3-2, rand()%3-2); //Allows for range of -2 -> 2
		//Pvector* location = new Pvector(x, y);
		location = Pvector(x, y);
		maxSpeed = 3.5;
		maxForce = 0.5;
	}

	//Destructor
	Boid::~Boid()
	{
		//cout << "Boid is being deleted by destructor!" << endl;
	}
	
	//Mutator Functions
	void applyForce(Pvector force);

	//Three Laws that boids follow
	Pvector Separation(vector<Boid> Boids);
	Pvector Alignment(vector<Boid> Boids);
	Pvector Cohesion(vector<Boid> Boids);

	//Functions involving SFML and visualisation linking
	float angle(Pvector v);
	Pvector seek(Pvector v);
	void run(vector <Boid> v);
	void update();
	void flock(vector <Boid> v);
	void borders();
};

#endif