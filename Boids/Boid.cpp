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

void Boid::applyForce(Pvector force)
{
	acceleration.addVector(force);
}


Pvector Boid::seek(Pvector v)
{
	Pvector desired, steer;
	desired.subVector(v);  // A vector pointing from the location to the target
	// Normalize desired and scale to maximum speed
	desired.normalize();
	desired.mulScalar(maxSpeed);
	// Steering = Desired minus Velocity
	//steer = PVector.sub(desired, velocity);
	steer.subTwoVector(desired,velocity);
	steer.limit(maxForce);  // Limit to maximum steering force
	return steer;
}


// Separation -- Should this be included in the flock class? Assumes boid flock
// Separation takes the vector of boids as a parameter and checks for the 
// distance between all the boids. If for any boid, that distance ends up being
// more than 
Pvector Boid::Separation(vector<Boid> boids)
{
	float desiredseparation = 25.0;
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
			Pvector diff;
			diff.subVector(boids[i].location);
			diff.normalize();
			diff.divScalar(d);        // Weight by distance
			steer.addVector(diff);
			count++;
		}
	}

	if (count >0)
	{
		steer.divScalar((float)count);
	}
	if (steer.magnitude() > 0) 
	{
		// Implement Reynolds: Steering = Desired - Velocity
		steer.normalize();
		steer.mulScalar(maxSpeed);
		steer.subVector(velocity);
		steer.limit(maxForce);
	}
	return steer;
}
// Alignment calculates the average velocity in the field of view and 
// manipulates the velocity of the Boid passed as parameter to adjust to that
// of nearb boids.
Pvector Boid::Alignment(vector<Boid> Boids)
{
	float neighbordist = 50;
	Pvector sum(0, 0);
	int count = 0;
	for (int i = 0; i < Boids.size(); i++)
	{
		float d = location.distance(Boids[i].location);
		if ((d > 0) && (d < neighbordist))
		{
			sum.addVector(Boids[i].velocity);
			count++;
		}
	}
	// If there are boids close enough for alignment...
	if (count > 0)
	{
		sum.divScalar((float)count); 		// Divide sum by the number of close boids
		sum.normalize();	   		// Turn sum into a unit vector, and
		sum.mulScalar(maxSpeed);    // Multiply by maxSpeed
		// Now we create the steer Pvector, which we'll return
		// Steer = Desired - Velocity
		Pvector steer;
		steer.subTwoVector(sum, velocity);
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
		//float d = distance(location, Boids[i].location);
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

void Boid::update()
{
	// Update velocity
	velocity.addVector(acceleration);
	// Limit speed
	velocity.limit(maxSpeed);
	location.addVector(velocity);
	// Reset accelertion to 0 each cycle
	acceleration.mulScalar(0);
}

void Boid::run(vector <Boid> v)
{
	flock(v);
	update();
	borders();
	render();
}

void Boid::render()
{

}


void Boid::flock(vector<Boid> v)
{
	Pvector sep = Separation(v);   // Separation
	Pvector ali = Alignment(v);      // Alignment
	Pvector coh = Cohesion(v);   // Cohesion
	// Arbitrarily weight these forces
	sep.mulScalar(1.5);
	ali.mulScalar(1.0);
	coh.mulScalar(1.0);
	// Add the force vectors to acceleration
	applyForce(sep);
	applyForce(ali);
	applyForce(coh);
}


void Boid::borders()
{
	/*r variable is ambiguous so will change it to 0 (r might be resolution)
	length and width is hardcoded for the time being for testing purposes*/
	if (location.x < 0) location.x = 600 + r; 
	if (location.y < 0) location.y = 600 + r; 
	if (location.x > 600) location.x = -r; 
	if (location.y > 600) location.y = -r; 

	/*
	if (location.x < -r) location.x = width+r;
    if (location.y < -r) location.y = height+r;
    if (location.x > width+r) location.x = -r;
    if (location.y > height+r) location.y = -r;
	*/
}
