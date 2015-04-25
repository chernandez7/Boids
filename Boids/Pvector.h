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
	float magnitude(Pvector v);
	float magnitude();
	float angleBetween(Pvector v1, Pvector v2);

	//Copy Function
	Pvector copy(Pvector v);

	//Need to be able to add/subtract vectors
	void addVector(Pvector v, Pvector v2);
	void addScalar(Pvector v, float x);
	void subVector(Pvector v, Pvector v2);
	void subScalar(Pvector v, float x);
	void mulVector(Pvector v, Pvector v2);
	void mulScalar(Pvector v, float x);
	void divVector(Pvector v, Pvector v2);
	void divScalar(Pvector v, float x);

	//Normalize
	Pvector Normalize(Pvector v);

};

#endif