#!/bin/bash
g++ -c main.cpp
# Below, compile the program and append the necessary libraries
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
# Run the executable
./sfml-app