### README ###

This project attempts to simulate flocking behavior, through the creation of simple entities called Boids (birdoids). These boids, which exist on a two-dimensional plane function through three simple rules -- alignment, cohesion, and separation.

Alignment causes boids to match velocity of nearby boids.
Cohesion causes boids to seek the center of mass of the nearest clump of boids.
Separation prevents boids from getting too close to each other. 

These three simple rules cause complex behavior to emerge, which is what makes the boid simulation interesting. The algorithms were originally written by Craig Reynolds in the 1980s.

### RUNNING THE SIMULATION ###

Currently, the simulation runs on Windows, through Visual Studio. Appropriate libraries must be linked -- we utilized SFML (Simple Fast Multimedia Library) to visualize the project. Instructions on how to do this through Visual Studio can be found at http://www.sfml-dev.org/tutorials/2.2/start-vc.php

Also, the project is able to run on Ubuntu and Debian-based distributions. To install the necessary libraries, run


```
#!c++

sudo apt-get install libsfml-dev
```


Included is a shell script (runSFMLapp.sh) which compiles and links the necessary libraries to the project. Further information on how to run the project and use SFML with Linux can be found at http://www.sfml-dev.org/tutorials/2.2/start-linux.php

### THE SIMULATION ###

Currently, the simulation needs to be improved. This can be done by finding the right set of parameters for the three rules, as well as messing with maxForce and maxSpeed in Boid.cpp. These include:

Boid.cpp:

* maxForce

* maxSpeed

* desiredseparation

* neighbordist

* mulScalar in Boid::flock

Future work might include creating a class that allows for these parameters to be set easily, as well as adding predators and optimizing the simulation. The program currently has terrible time complexity -- currently, the program iterates through the flock of boids -- each boid then iterates through the full flock three times to calculate each algorithm.


### To do ###

### Goals ###
* General Layout: Create 2D application that simulates boids. Include functionality that allows us to change settings regarding boid behavior (e.g., velocity, flocking, etc). If time allows, predators.
* Also if time allows, user interactivity -- controlling flocking behavior? Controlling predators?

### How to install SFML
* [SFML Library](http://www.sfml-dev.org/index.php) - Visualizing the project. When installing SFML Library, choose C++11

### How to clone this repository while using Visual Studio ###
* Open up Visual Studio
* "Open from Source Control"
* Input the cloning link from Bitbucket repo
* Visual Studio might prompt you to install Git GUI. Do so. Once that's done, you should see the solution "Boids" on the left side. Double click it and you should be good to go.
To commit saved changes to the bitbucket repo, open up Git GUI and open up the Boids folder. From there you commit. Then when you want to push up to the Bitbucket repo, you click push.

=======
### Other Goals ###
* [SFML Library](http://www.sfml-dev.org/index.php) - Visualizing the project. When installing SFML Library, choose C++11
* General Layout: Create 2D application that simulates boids. Include functionality that allows us to change settings regarding boid behavior (e.g., velocity, flocking, etc). If time allows, predators.
* Also if time allows, user interactivity -- controlling flocking behavior? Controlling predators?