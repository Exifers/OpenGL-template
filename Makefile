glutlib = /home/emmanuel/Downloads/freeglut-3.0.0/lib/

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++17

fls = $(shell find src/ -type f -name "*.cc")
bin = main

all:
	$(CXX) $(CXXFLAGS) $(fls) -lGL -lGLU -lglut -lGLEW -lX11 -o $(bin)
