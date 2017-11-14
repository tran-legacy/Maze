/*************************
 * Tran Le
 * CSS342 - Project 4
 * [INSERT TIME TOOK HERE] 
 * Vim on Cygwin 
**************************/ 

//////////////////////////////////////
// mazeRunner class defines the runner that will solve the given maze
// - will print out graphical and coordinate representation of path taken
// - if no exit, will print "No exit - Sartre was right
//////////////////////////////////////
#ifndef MAZERUNNER_H
#define MAZERUNNER_H
#include "maze.h" 
#include <iostream> 

class MazeRunner {
public: 
	MazeRunner(); 
	MazeRunner(Maze& maze); 
	~MazeRunner(); 
	void solve() const; 	
private:
	Maze maze; 
	
	// Consts 
	const char PATH = '+'; 
	static const char WALL = '#'; 
	static const char EXIT = 'o'; 
};
#endif //!MAZERUNNER_H

