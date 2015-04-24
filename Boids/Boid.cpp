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

//Seperation checks for nearby boids and does some action when getting closer (Seperate, collide, avoid)
Pvector Boid::Seperation(Pvector Boid)
{

}
//Alignment calculates the average velocity in the field of view and manipulates it accordingly
Pvector Boid::Alignment(Pvector Boid)
{

}
//Cohesion Finds the average location and manipulates the steering force to move in that direction.
Pvector Boid::Cohesion(Pvector Boid)
{

}