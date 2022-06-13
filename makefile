  all: std-array.x

  std-array.x: array.hpp main.cpp
				g++ main.cpp -o std-array.x -std=c++2a

  clean: 
	  $(RM) std-array