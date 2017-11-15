/*********************
 * Tran Le
 * CSS342 - Project 4 
 * [insert time took here] 
 * Vim on Cygwin 
*********************/

//////////////////////////////////////
// mazeRunner.cpp is implementation of mazeRunner.h
// //////////////////////////////////

#include "mazeRunner.h" 
#include "maze.h"
#include <iostream> 
/***************CONSTRUCTORS*****************/
MazeRunner::MazeRunner(Maze& maze) {
	this->maze = maze;
}

/**************FUNCTIONS*******************/
//// Recursively walk through maze and keeps track of path ////
bool MazeRunner::findPath(const int Y, const int X) {
	// If current position is outside of maze
	if ( X < 0 || X >= maze.getWidth() ||
		 Y < 0 || Y >= maze.getHeight()) {
		return false; 
	} 
	// If current position is goal
	//if (this->playerX == maze.getExitX() && this->playerY == maze.getExitY()) {
	if (maze.getChar(Y, X) == EXIT) {
		return true;
	}
	// If current position is not open, aka it's a wall
	if (maze.getChar(Y, X) == WALL) {
		return false; 
	}
	// If current position is + (taken before) return false
	if (maze.getChar(Y, X) == PATH) {
		return false;
	}
	//////////////// MARK X,Y AS PART OF SOLUTION
	
	pathVector.push_back("[" + std::to_string(Y) + "," + std::to_string(X) + "]");
	maze.getChar(Y, X) = PATH; 
	// Go North
	if (findPath(Y-1, X) == true) {
		return true;
	}
	// Go East 
	if (findPath(Y, X+1) == true) {
		return true;
	}
	// Go South 
	if (findPath(Y+1, X) == true) {
		return true; 
	}
	// Go West
	if (findPath(Y, X-1) == true) {
		return true; 
	}

	/////////////////////// UNMARK X, Y AS PART OF SOLUTION PATH
	pathVector.pop_back(); 
	maze.getChar(Y,X) = SPACE; 
	return false;
}

//// Print path in form of [Y,X]->[Y,X]->[Y,X]->EXIT
void MazeRunner::printPath() {
	this->maze.print();
	std::cout << std::endl;

	for (int i = 0; i < pathVector.size(); ++i) {
		std::cout << pathVector[i] << "->";
	}
	std::cout << "EXIT" << std::endl;
}
//// calls findPath and handle no exit ////
//void MazeRunner::solve() {
//	if (this->findPath(this->maze.getStartingY(), this->maze.getStartingX())) {
//		this->printPath();
//	} else {
//		std::cout << "No exit - Sartre was right" << std::endl;
//	}
//}
