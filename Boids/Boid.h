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
		Pvector* acceleration = new Pvector(0, 0);
		Pvector* velocity = new Pvector(0, 0);
		Pvector* location = new Pvector(x, y);
		maxSpeed = 3;
		maxForce = 2;
	}

	//Destructor
	Boid::~Boid()
	{
		//cout << "Boid is being deleted by destructor!" << endl;
	}
	
	//Mutator Functions
	void changeMaxSpeed(float speed);
	void changeMaxForce(float force);
	void applyForce(Pvector force);

	//Three Laws that boids follow
	Pvector Separation(vector<Boid> Boids);
	Pvector Alignment(vector<Boid> Boids);
	Pvector Cohesion(vector<Boid> Boids);

	//Functions involving SFML and visualisation linking
	Pvector seek(Pvector v);
	void run(vector <Boid> v);
	void render();
	void update();
	void flock(vector <Boid> v);
	void borders();
};

#endif