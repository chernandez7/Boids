#include "Pvector.h"

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

	Boid(float x, float y);
	/*{
		//initialize acceleration
	//	acceleration = new Pvector(0, 0);
		//initialize velocity
		//velocity = new Pvector(0, 0);
		//initialize location
		//location = new Pvector(0, 0);
		//initialize r
		r = 0;
		//initialize max speed
		maxSpeed = 3;
		//initialize max force
		maxForce = 2;
	}*/

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