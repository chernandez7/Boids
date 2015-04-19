// This file defines the boid class. This includes the attributes found in
// boids -- speed, location on the board, acceleration, etc.
// To do: Create PVector and implement it Here
#include <iostream>
#include <vector>
#include <string>
//#include <Boid.h>

using namespace std;

#ifndef BOID_H_
#define BOID_H_

class Boid
{
public:
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

private:

	Boid(float x, float y)
	{
		//initialize acceleration
		acceleration = new Pvector(0, 0);
		//initialize velocity
		//initialize location
		//initialize r
		//initialize max speed
		//initialize max force
	}

	//Accessor Functions
	Pvector getVelocity();
	Pvector getAcceleration();
	Pvector getLocation();
	float getR();
	float getMaxSpeed();
	float getMaxForce();

	//Mutator Functions
	void changeVelocity(float speed);
	void changeAcceleration(Pvector acceleration);
	void changeLocation(Pvector location);
	void changeR(float x);
	void changeMaxSpeed(float speed);
	void changeMaxForce(float force);
};

#endif BOID_H_

// =============================================== //
// ======== Boid Functions from Boid.h ========= //
// =============================================== //


//Get Speed
Pvector Boid::getVelocity()
{
	return velocity;
}

//Get Acceleration
Pvector Boid::getAcceleration()
{
	return acceleration;
}

//Get Location
Pvector Boid::getLocation()
{
	return location;
}

//Get R
float Boid::getR()
{
	return r;
}

//Get Max Speed
float Boid::getMaxSpeed()
{
	return maxSpeed;
}

//Get Max Force
float Boid::getMaxForce()
{
	return maxForce;
}

//Manipulate Velocity

//Manipulate acceleration

//Manipulate location

//Manipulate Field of Vision
void Boid::changeR(float x)
{
	r = x;
}

//Manipulate Max Speed
void Boid::changeMaxSpeed(float speed)
{
	maxSpeed = speed;
}

//Manipulate Max Force
void Boid::changeMaxForce(float force)
{
	maxForce = force;
}
