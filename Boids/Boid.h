#define BOID_H_
#ifndef BOID_H_

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