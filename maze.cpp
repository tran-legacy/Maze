/*********************
 * Tran Le
 * CSS342 - Project 4 
 * [insert time took here] 
 * Vim on Cygwin 
*********************/

//////////////////////////
// maze.cpp is implementation of maze.h
// ///////////////////////

#include <iostream> 
#include <fstream>
#include <string> 
#include "maze.h" 

/***********CONSTRUCTORS**************/
Maze::Maze() {
	this->height = 0; this->width = 0; 
} 

//// Constructor takes in a file and copies it into this object ////
Maze::Maze(std::ifstream& file) {
	// Get first line and initalize variables
	std::string firstLine = ""; 
	std::getline(file, firstLine);
	// getline does not get newline character 
	// so '/n' was added so functions could work properly
	firstLine += '\n'; 
	firstLineInit(firstLine);
	
	// Initalize size of maze and put chars in maze
	maze = new char*[this->height]; 
	for (int i =0; i < this->height; ++i) { maze[i] = new char[this->width]; }

	int column; 
	std::string temp = ""; 	
	for (int row = 0; row < this->height; ++row) {
		std::getline(file, temp);
		for (column = 0; column < this->width; ++column) {
		   	if (temp[column] == EXIT) {
				this->haveExit = true;
				// There should only be one exit given, it's coordinate will be kept track
				this->exitY = row; this->exitX = column; 
			}	
			maze[row][column] = temp[column]; 

		}
		if (temp[column + 1] == WALL) {
			std::cout << 
				"ERROR: Initialized width and height does not match up with maze drawing"
				<< std::endl;
			throw InvalidMaze();
		}
		temp = ""; 	
	}

	// Exception handling, if startingY or startingX is out of range, throw exception
	if (startingY > height || startingX > width) {
		std::cout << "Invalid starting point" << std::endl;
		throw InvalidStartingPoint(); 
	}
   	// Else if starting point is a wall, throw exception	
	else if (maze[startingY][startingX] == WALL) {
	   	std::cout << "Invalid starting point" << std::endl;	
		throw InvalidStartingPoint(); 
	} 
	// If there's no given exit, throw exception
	if (!haveExit) {
		std::cout << "No exit - Sartre was right" << std::endl;
		throw InvalidMaze();
	}
	// Else there's an exit but it's block, therefore not reachable
	else if (maze[exitY-1][exitX] == WALL && maze[exitY][exitX+1] == WALL &&
			 maze[exitY+1][exitX] == WALL && maze[exitY][exitX-1] == WALL) {
		std::cout << "No exit - Sartre was right" << std::endl;
		throw InvalidMaze();
	}

}

//// private helper function that handles the first line of the inputted file //// 
//// in the constructor
void Maze::firstLineInit(std::string& firstLine) {
 	std::string temp = ""; 
	int array[4]; 
	int currentNumber = 0; 
	for (int i =0; i < firstLine.size(); ++i) {
		// If current char is space or a new line char and temp is not empty, add temp to array
		if (firstLine[i] == ' ' || firstLine[i] == '\n') {
			if (!temp.empty()) {
				// Convert string to int and add it on array 
				array[currentNumber] = std::stoi(temp);
				temp = ""; // Reset temp
				++currentNumber; // Next number added will go in correct index
			}
		} 
		// Else it's a number, then append to temp
		else if (firstLine[i] >= '0' && firstLine[i] <= '9') {
			temp += firstLine[i]; 
		}
	}
	this->height = array[0]; 
	this->width = array[1]; 
	this->startingY = array[2]; 
	this->startingX = array[3]; 
}

/*****************DESTRUCTOR******************/
Maze::~Maze() {
	for (int row = 0; row < height; ++row) {
		delete[] maze[row]; 
	}	
	delete[] maze;
}

/****************Functions*******************/
//// print out the maze ////
void Maze::print() const {
	for (int row = 0; row < this->height; ++row) {
		for (int column = 0; column < this->width; ++column) {
			std::cout << maze[row][column]; 
		}
		std::cout << std::endl;
	}
}
