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

	Pvector(float x, float y)
	{
		//initialize x
		x = 0;
		//initialize y
		y=0;
	}
	
	//Accessor Functions
	float getX();
	float getY();

	//Mutator Functions
	void set(float x, float y);
	void setV(Pvector v);

	//Calculating Functions
	float distance(Pvector v1, Pvector v2);
	float dotProduct(Pvector v1, Pvector v2);
	float magnitude(Pvector v);
	float angleBetween(Pvector v1, Pvector v2);

	//Copy Function
	Pvector copy(Pvector v);

	//Need to be able to add/subtract vectors
	void addVector(Pvector v, Pvector v2);
	void addScaler(Pvector v, float x);
	void subVector(Pvector v, Pvector v2);
	void subScaler(Pvector v, float x);
	void mulVector(Pvector v, Pvector v2);
	void mulScaler(Pvector v, float x);
	void divVector(Pvector v, Pvector v2);
	void divScaler(Pvector v, float x);


};

#endif PVECTOR_H_