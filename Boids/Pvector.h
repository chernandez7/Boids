// The Pvector class implements Euclidian vectors -- that is, each vector has
// both a magnitude and a direction. We use Pvectors for implementing movement
// and the three Boid rules -- cohesion, separation, and matching velocity
// through the use of acceleration, force, and velocity vectors. 
#ifndef PVECTOR_H_
#define PVECTOR_H_

class Pvector
{
public:
	float x;
	float y;
	//Initialized Pvector and sets values to 0. ?
	Pvector()
	{}
	// Initializes Pvector with x and y components.
	Pvector(float xComp, float yComp)
	{
		//initialize x
		//initialize y
		x = xComp;
		y = yComp;
	}
	
	//Accessor Functions
	//Commented out for now.
	/*float getX();
	float getY();*/

	//Mutator Functions
	void set(float x, float y);
	void setV(Pvector v);

	//Calculating Functions
	float distance(Pvector v1, Pvector v2);
	float dotProduct(Pvector v1, Pvector v2);
	float magnitude();
	void setMagnitude(float x);
	float angleBetween(Pvector v1, Pvector v2);

	//Copy Function
	Pvector copy(Pvector v);

	//Need to be able to add/subtract vectors
	void addVector(Pvector v);
	void addScalar(float x);
	void subVector(Pvector v);
	void subScalar(float x);
	void mulVector(Pvector v);
	void mulScalar(float x);
	void divVector(Pvector v);
	void divScalar(float x);

	//Normalize
	Pvector normalize();

	void limit(double max);

};

#endif