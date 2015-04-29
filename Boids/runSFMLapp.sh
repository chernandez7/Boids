#!/bin/bash
rm -f *.o sfml-app *h.gch
g++ -c main.cpp Boid.cpp Pvector.cpp Flock.cpp
# Below, compile the program and append the necessary libraries
g++ main.o Boid.o Pvector.o Flock.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
# Run the executable
./sfml-app