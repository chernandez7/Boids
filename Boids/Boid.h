#include "Pvector.h"
#include <vector>

using namespace std;

#ifndef BOID_H_
#define BOID_H_

class Boid
{
public:
	float x;
	float y;

	//location (Pvector)
	Pvector location;
	//velocity (Pvector)
	Pvector velocity;
	//acceleration (Pvector)
	Pvector acceleration;
	//Max speed?
	float maxSpeed;
	//steering power?
	float maxForce;
	float r; // Field of Vision?



	Boid(float x, float y)
	{
		//initialize acceleration
		Pvector acceleration(0, 0);
		//initialize velocity
		Pvector velocity(0, 0);
		//initialize location
		Pvector location(x, y);
		//initialize r
		r = 0;
		//initialize max speed
		maxSpeed = 3;
		//initialize max force
		maxForce = 2;
	}
	Boid::~Boid()
	{
		/*
		delete acceleration;
		delete velocity;
		delete location;
		*/
	}
	
	/* As all of our methods within Boid.h are public, we do not need accessor
	functions. Commenting these out for now. 
	//Accessor Functions
	Pvector getVelocity();
	Pvector getAcceleration();
	Pvector getLocation();
	float getR();
	float getMaxSpeed();
	float getMaxForce();
	*/

	//Mutator Functions
	void changeVelocity(float speed);
	void changeAcceleration(Pvector acceleration);
	void changeLocation(Pvector location);
	void changeR(float x);
	void changeMaxSpeed(float speed);
	void changeMaxForce(float force);
	void applyForce(Pvector force);

	//Need to add the 3 laws functions + .cpp functionality of them

	//Separation
	Pvector Separation(vector<Boid> Boids);
	//Alignment
	Pvector Alignment(vector<Boid> Boids);
	//Cohesion
	Pvector Cohesion(vector<Boid> Boids);

	Pvector seek(Pvector v);
	void run(vector <Boid> v);
	void render();
	void update();
	void flock(vector <Boid> v);
	void borders();

};

#endif