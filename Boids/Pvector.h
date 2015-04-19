#ifndef PVECTOR_H_
#define PVECTOR_H_

class Pvector
{
public:

	float x;
	float y;

private:

	//Initialized Pvector and sets values to 0. ?
	Pvector()
	{}

	Pvector(float x, float y)
	{
		//initialize x

		//initialize y
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

};

#endif PVECTOR_H_