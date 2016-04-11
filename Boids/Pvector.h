#include <iostream>
using namespace std;

#ifndef PVECTOR_H_
#define PVECTOR_H_

// The Pvector class implements Euclidian vectors -- that is, each vector has
// both a magnitude and a direction. We use Pvectors for implementing movement
// and the three Boid rules -- cohesion, separation, and matching velocity
// through the use of acceleration, force, and velocity vectors.

class Pvector {

public:
	float x;
	float y;

	//Constructors
	Pvector() {}

	Pvector(float xComp, float yComp)
	{
		x = xComp;
		y = yComp;
	}

	//Mutator Functions
	void set(float x, float y);

	//Scalar functions scale a vector by a float
	void addVector(Pvector v);
	void addScalar(float x);

	void subVector(Pvector v);
	static Pvector subTwoVector(Pvector v, Pvector v2);
	void subScalar(float x);

	void mulVector(Pvector v);
	void mulScalar(float x);

	void divVector(Pvector v);
	void divScalar(float x);

	void limit(double max);

	//Calculating Functions
	float distance(Pvector v) const;
	float dotProduct(Pvector v) const;
	float magnitude() const;
	void setMagnitude(float x);
	float angleBetween(Pvector v) const;
	void normalize();

	static Pvector copy(Pvector v);
};

#endif
