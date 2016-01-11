#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Boid.h"

// Global Variables for borders()
// desktopTemp gets screen resolution of PC running the program
sf::VideoMode desktopTemp = sf::VideoMode::getDesktopMode();
const int window_height = desktopTemp.height;
const int window_width = desktopTemp.width;

// =============================================== //
// ======== Boid Functions from Boid.h =========== //
// =============================================== //

Boid::Boid(float x, float y)
{
	acceleration = Pvector(0, 0);
	velocity = Pvector(rand() % 3 - 2, rand() % 3 - 2);
	location = Pvector(x, y);
	maxSpeed = 3.5;
	maxForce = 0.5;
}

Boid::Boid(float x, float y, bool predCheck)
{
	predator = predCheck;
	if (predCheck == true) {
		maxSpeed = 7.5;
		maxForce = 1.5;
		velocity = Pvector(rand() % 5 - 1, rand() % 5 - 1);
	}
	else {
		maxSpeed = 5.5;
		maxForce = 0.5;
		velocity = Pvector(rand() % 5 - 2, rand() % 5 - 2);
	}
	acceleration = Pvector(0, 0);
	location = Pvector(x, y);
}

// Adds force Pvector to current force Pvector
void Boid::applyForce(Pvector force)
{
	acceleration.addVector(force);
}

// Separation
// Keeps boids from getting too close to one another
Pvector Boid::Separation(vector<Boid> boids)
{
	// Distance of field of vision for separation between boids
	float desiredseparation = 20;
	Pvector steer(0, 0);
	int count = 0;
	// For every boid in the system, check if it's too close
	for (int i = 0; i < boids.size(); i++) {
		// Calculate distance from current boid to boid we're looking at
		float d = location.distance(boids[i].location);
		// If this is a fellow boid and it's too close, move away from it
		if ((d > 0) && (d < desiredseparation)) {
			Pvector diff(0, 0);
			diff = diff.subTwoVector(location, boids[i].location);
			diff.normalize();
			diff.divScalar(d);      // Weight by distance
			steer.addVector(diff);
			count++;
		}
		// If current boid is a predator and the boid we're looking at is also
		// a predator, then separate only slightly
		if ((d > 0) && (d < desiredseparation) && predator == true
			&& boids[i].predator == true) {
			Pvector pred2pred(0, 0);
			pred2pred = pred2pred.subTwoVector(location, boids[i].location);
			pred2pred.normalize();
			pred2pred.divScalar(d);
			steer.addVector(pred2pred);
			count++;
		}
		// If current boid is not a predator, but the boid we're looking at is
		// a predator, then create a large separation Pvector
		else if ((d > 0) && (d < desiredseparation + 70) && boids[i].predator == true) {
			Pvector pred(0, 0);
			pred = pred.subTwoVector(location, boids[i].location);
			pred.mulScalar(900);
			steer.addVector(pred);
			count++;
		}
	}
	// Adds average difference of location to acceleration
	if (count > 0)
		steer.divScalar((float)count);
	if (steer.magnitude() > 0) {
		// Steering = Desired - Velocity
		steer.normalize();
		steer.mulScalar(maxSpeed);
		steer.subVector(velocity);
		steer.limit(maxForce);
	}
	return steer;
}

// Alignment
// Calculates the average velocity of boids in the field of vision and
// manipulates the velocity of the current boid in order to match it
Pvector Boid::Alignment(vector<Boid> Boids)
{
	float neighbordist = 70; // Field of vision

	Pvector sum(0, 0);
	int count = 0;
	for (int i = 0; i < Boids.size(); i++) {
		float d = location.distance(Boids[i].location);

		if ((d > 0) && (d < neighbordist)) { // 0 < d < 50
			sum.addVector(Boids[i].velocity);
			count++;
		}
	}
	// If there are boids close enough for alignment...
	if (count > 0) {
		sum.divScalar((float)count);// Divide sum by the number of close boids (average of velocity)
		sum.normalize();            // Turn sum into a unit vector, and
		sum.mulScalar(maxSpeed);    // Multiply by maxSpeed
		// Steer = Desired - Velocity
		Pvector steer;
		steer = steer.subTwoVector(sum, velocity); //sum = desired(average)
		steer.limit(maxForce);
		return steer;
	}
	else {
		Pvector temp(0, 0);
		return temp;
	}
}

// Cohesion
// Finds the average location of nearby boids and manipulates the
// steering force to move in that direction.
Pvector Boid::Cohesion(vector<Boid> Boids)
{
	float neighbordist = 25;
	Pvector sum(0, 0);
	int count = 0;
	for (int i = 0; i < Boids.size(); i++) {
		float d = location.distance(Boids[i].location);

		if (Boids[i].predator) neighbordist = 15;

		if ((d > 0) && (d < neighbordist)) {
			sum.addVector(Boids[i].location);
			count++;
		}
	}
	if (count > 0) {
		sum.divScalar(count);
		return seek(sum);
	}
	else {
		Pvector temp(0, 0);
		return temp;
	}
}

// Limits the maxSpeed, finds necessary steering force and
// normalizes vectors
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

// Modifies velocity, location, and resets acceleration with values that
// are given by the three laws.
void Boid::update()
{
	//To make the slow down not as abrupt
	acceleration.mulScalar(.35);
	// Update velocity
	velocity.addVector(acceleration);
	// Limit speed
	velocity.limit(maxSpeed);
	location.addVector(velocity);
	// Reset accelertion to 0 each cycle
	acceleration.mulScalar(0);
}

// Run flock() on the flock of boids.
// This applies the three rules, modifies velocities accordingly, updates data,
// and corrects boids which are sitting outside of the SFML window
void Boid::run(vector <Boid> v)
{
	flock(v);
	update();
	borders();
}

// Applies the three laws to the flock of boids
void Boid::flock(vector<Boid> v)
{
	Pvector sep = Separation(v);
	Pvector ali = Alignment(v);
	Pvector coh = Cohesion(v);
	// Arbitrarily weight these forces
	sep.mulScalar(1.5);
	ali.mulScalar(1.0); // Might need to alter weights for different characteristics
	coh.mulScalar(1.0);
	// Add the force vectors to acceleration
	applyForce(sep);
	applyForce(ali);
	applyForce(coh);
}

// Checks if boids go out of the window and if so, wraps them around to
// the other side.
void Boid::borders()
{
	if (location.x < 0)    location.x += window_width;
	if (location.y < 0)    location.y += window_height;
	if (location.x > window_width) location.x -= window_width;
	if (location.y > window_height) location.y -= window_height;
}

// Calculates the angle for the velocity of a boid which allows the visual
// image to rotate in the direction that it is going in.
float Boid::angle(Pvector v)
{
	// From the definition of the dot product
	float angle = static_cast<float>(atan2(v.x, -v.y) * 180 / M_PI);
	return angle;
}
