// This file defines the boid class. This includes the attributes found in
// boids -- speed, location on the board, acceleration, etc.
#include <iostream>
#include <vector>
#include <string>
#include <SFML\Window.hpp>
#include "Boid.h"

//Global Variables for borders()
sf::VideoMode desktopTemp = sf::VideoMode::getDesktopMode(); //Gets screen resolution of PC running the program
const int window_height = desktopTemp.height;
const int window_width = desktopTemp.width;

#define w_height window_height
#define w_width window_width
#define PI 3.141592635

using namespace std;

// =============================================== //
// ======== Boid Functions from Boid.h ========= //
// =============================================== //



//Adds force Pvector to current force Pvector
void Boid::applyForce(Pvector force)
{
	acceleration.addVector(force);
}

// Function that checks and modifies the distance 
// of a boid of it breaks the law of separation.
Pvector Boid::Separation(vector<Boid> boids)
{
	float desiredseparation = 25; //Distance of field of vision for separation between boids

	Pvector steer(0, 0);
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

		float d = location.distance(boids[i].location);

		if ((d > 0) && (d < desiredseparation))
		{
			Pvector diff(0,0);
			
			diff = diff.subTwoVector(location,boids[i].location); 
			diff.normalize();
			diff.divScalar(d);        // Weight by distance
			steer.addVector(diff);
			count++;
		}
	}
	if (count >0)
	{
		steer.divScalar((float)count); //adds average difference of location to acceleration
	}
	if (steer.magnitude() > 0) 
	{
		// Steering = Desired - Velocity
		steer.normalize();
		steer.mulScalar(maxSpeed);
		steer.subVector(velocity);
		steer.limit(maxForce);
	}
	return steer;
}

// Alignment calculates the average velocity in the field of view and 
// manipulates the velocity of the Boid passed as parameter to adjust to that
// of nearby boids.
Pvector Boid::Alignment(vector<Boid> Boids)
{
	float neighbordist = 50;

	Pvector sum(0, 0);	
	int count = 0;
	for (int i = 0; i < Boids.size(); i++)
	{
		float d = location.distance(Boids[i].location);
		if ((d > 0) && (d < neighbordist)) //0 < d < 50
		{
			sum.addVector(Boids[i].velocity);
			count++;
		}
	}
	// If there are boids close enough for alignment...
	if (count > 0)
	{
		sum.divScalar((float)count); 		// Divide sum by the number of close boids (average of velocity)
		sum.normalize();	   		// Turn sum into a unit vector, and
		sum.mulScalar(maxSpeed);    // Multiply by maxSpeed
		// Now we create the steer Pvector, which we'll return
		// Steer = Desired - Velocity
		Pvector steer; 
		steer = steer.subTwoVector(sum, velocity); //sum = desired(average)  
		steer.limit(maxForce);
		return steer;
	} else {
		Pvector temp(0, 0);
		return temp;
	}
}

// Cohesion finds the average location of nearby boids and manipulates the 
// steering force to move in that direction.
Pvector Boid::Cohesion(vector<Boid> Boids)
{
	float neighbordist = 50;

	Pvector sum(0, 0);	
	int count = 0;
	for (int i = 0; i < Boids.size(); i++)
	{
		float d = location.distance(Boids[i].location);
		if ((d > 0) && (d < neighbordist))
		{
			sum.addVector(Boids[i].location);
			count++;
		}
	}
	if (count > 0)
	{
		sum.divScalar(count);
		return seek(sum);
	} else {
		Pvector temp(0,0);
		return temp;
	}
}

//Seek function limits the maxSpeed, finds necessary steering force and normalizes the vectors.
Pvector Boid::seek(Pvector v)
{
	Pvector desired;
	desired.subVector(v);  // A vector pointing from the location to the target
	// Normalize desired and scale to maximum speed
	desired.normalize();
	desired.mulScalar(maxSpeed);
	// Steering = Desired minus Velocity
	acceleration.subTwoVector(desired, velocity);
	acceleration.limit(maxForce);  // Limit to maximum steering force
	return acceleration;
}

//Update modifies velocity, location, and resets acceleration with values that
//are given by the three laws.
void Boid::update()
{
	//To make the slow down not as abrupt
	acceleration.mulScalar(.4);
	// Update velocity
	velocity.addVector(acceleration);
	// Limit speed
	velocity.limit(maxSpeed);
	location.addVector(velocity);
	// Reset accelertion to 0 each cycle
	acceleration.mulScalar(0);
}

//Run runs flock on the flock of boids for each boid.
//Which applies the three rules, modifies accordingly, updates data, checks is data is
//out of range, fixes that for SFML, and renders it on the window.
void Boid::run(vector <Boid> v)
{
	flock(v);
	update();
	borders();
}

//Applies all three laws for the flock of boids and modifies to keep them from
//breaking the laws.
void Boid::flock(vector<Boid> v) 
{
	Pvector sep = Separation(v);   // Separation
	Pvector ali = Alignment(v);      // Alignment
	Pvector coh = Cohesion(v);   // Cohesion
	// Arbitrarily weight these forces
	sep.mulScalar(1.5);
	ali.mulScalar(1.0); //might need to alter weights for different characteristics
	coh.mulScalar(1.0);
	// Add the force vectors to acceleration
	applyForce(sep);
	applyForce(ali);
	applyForce(coh);
}

//Checks if boids go out of the window and if so, wraps them around to the other side.
void Boid::borders()
{
	if (location.x < 0) location.x += w_width; 
	if (location.y < 0) location.y += w_height;
	if (location.x > 1000) location.x -= w_width;
	if (location.y > 1000) location.y -= w_height;
}

//Calculates the angle for the velocity of a boid which allows the visual image to rotate in the direction that it is going in.
float Boid::angle(Pvector v)
{
	float angle = (float)(atan2(v.x, -v.y) * 180 / PI); // using Dot-product definition
	return angle;
}