#include "Boid.h"
#include "Flock.h"

using namespace std;

// =============================================== //
// ======== Flock Functions from Flock.h ========= //
// =============================================== //

void Flock::addBoid(Boid b)
{
	flock.push_back(b);
}