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
#include <string>
#include <vector>

class MazeRunner {
public: 
	MazeRunner(){} 
	MazeRunner(Maze& maze); 
	~MazeRunner(){} 
	bool findPath(const int Y, const int X); 
	void printPath(); 	
//	void solve(); 
private:
	// SHOULD THIS BE A POINTER??????????????????????
	Maze maze; 
	std::vector<std::string> pathVector; 	
	// Consts 
	const char PATH = '+'; 
	static const char WALL = '#'; 
	static const char SPACE = ' ';
	static const char EXIT = 'o'; 
};
#endif //!MAZERUNNER_H

