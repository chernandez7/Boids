// This file defines the boid class. This includes the attributes found in
// boids -- speed, location on the board, acceleration, etc.
// To do: Create PVector and implement it Here
#include <iostream>
#include <vector>
#include <string>
#include "Boid.h"
using namespace std;

// =============================================== //
// ======== Boid Functions from Boid.h ========= //
// =============================================== //


// Get Speed
/*
Accessor functions commented out for now. In order to access Boid data, such as
velocity, acceleration, location, etc, a Boid.DATATYPE call is sufficient.
Pvector Boid::getVelocity()
{
	return velocity;
}

// Get Acceleration
Pvector Boid::getAcceleration()
{
	return acceleration;
}

// Get Location
Pvector Boid::getLocation()
{
	return location;
}

// Get R
float Boid::getR()
{
	return r;
}

// Get Max Speed
float Boid::getMaxSpeed()
{
	return maxSpeed;
}

// Get Max Force
float Boid::getMaxForce()
{
	return maxForce;
}
*/

// Manipulate Velocity

// Manipulate acceleration

// Manipulate location

// Manipulate Field of Vision
void Boid::changeR(float x)
{
	r = x;
}

// Manipulate Max Speed
void Boid::changeMaxSpeed(float speed)
{
	maxSpeed = speed;
}

// Manipulate Max Force
void Boid::changeMaxForce(float force)
{
	maxForce = force;
}

// Separation -- Should this be included in the flock class? Assumes boid flock
// Separation takes the vector of boids as a parameter and checks for the 
// distance between all the boids. If for any boid, that distance ends up being
// more than 
Pvector Boid::Seperation(vector<Boid> boids)
{
	float desiredseparation = 25.0;
	Pvector steer(0,0);
	int count = 0;
	// For every boid in the system, check if it's too close
	for (int i = 0; i < boids.size(); i++)
	{
		// Distance calculates distance between two points, (considering a
		// point as a vector object). So,
		// 1. Calculate distance between each each Boid to all the other boids
		// 2. If that distance is greater than 0 (to avoid doing comparisons
		//    with itself) and smaller than the desiredseparation, create a
		//    Pvector that points away from all of the other boids

		float d = boids[i].Pvector.distance()
	}
}
// Alignment calculates the average velocity in the field of view and 
// manipulates the velocity of the Boid passed as parameter to adjust to that
// of nearb boids.
Pvector Boid::Alignment(Pvector Boid)
{
	float neighbordist = 50;

	return steer;

}
// Cohesion finds the average location of nearby boids and manipulates the 
// steering force to move in that direction.
Pvector Boid::Cohesion(Pvector Boid)
{
	float neighbordist = 50;
}