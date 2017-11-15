/*************************
 * Tran Le
 * CSS342 - Project 4
 * 13 hours 
 * Vim on Cygwin 
**************************/ 

///////////////////////////
// Maze Class 
// - A maze made from reading in an inputted file 
// - It sets the starting position of the runner   
///////////////////////////

#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <fstream>
class Maze {
public: 
	// Empty exception classes
	class InvalidStartingPoint {};
	class InvalidMaze{};
	// Constructor
	Maze();
	Maze(std::ifstream& file);
	// Destructor
	~Maze();
	// Functions
	void print() const;

	// Getters
	int getStartingX() const { return this->startingX; }
	int getStartingY() const { return this->startingY; }
	int getHeight() const { return this->height;}
	int getWidth() const { return this->width; }
	int getExitX() const { return this->exitX; }
	int getExitY() const { return this->exitY; }
	char& getChar(const int Y, const int X) {
		return maze[Y][X]; 
	}
	Maze& operator=(const Maze& rhs);
private:
	// 2 dimensional array 
	char* *maze;
	int startingX; 
	int startingY; 
	int height; 
	int width; 
	int exitY; 
	int exitX;
	static const char WALL = '#'; 
	static const char EXIT = 'o';	
	void firstLineInit(std::string& firstLine);
};

#endif //!MAZE_H
