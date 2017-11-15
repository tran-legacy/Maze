/*************************
 * Tran Le
 * CSS342 - Project 4
 * 13 hours 
 * Vim on Cygwin 
**************************/ 

///////////////////////////////
// mazeRun.cpp is the main 
// It takes in a maze file (created by instructor) for testing
///////////////////////////////

#include <iostream> 
#include <fstream>
#include <string>
#include "maze.h" 
#include "mazeRunner.h" 

int main(int argc, char* *argv) {
	if (argc == 2) {
		std::ifstream infile(argv[1]); 
		if(infile.is_open() && infile.good()) {
			// Make maze
			Maze maze(infile); 
			std::cout << maze.getHeight() << " " << maze.getWidth() << " " 
				<< maze.getStartingY() << " " << maze.getStartingX() << std::endl;
			std:: cout << "MAZE" << std::endl;
			maze.print();
			// The maze runner is given a maze to solve 
			// solve() will print out the maze and the path the runner took 
			// and a string representation of the route took 
			MazeRunner runner(maze);
			if (runner.findPath(maze.getStartingY(), maze.getStartingX())) {
				std::cout << std::endl << "SOLVED MAZE" << std::endl; 
				runner.printPath();
			} else {
				std::cout << "No exit - Sartre was right" << std::endl;
			}


			infile.close(); 
		} else if (argc > 2) {
			std::cout << "One file at a time please" << std::endl; 
		} else {
			std::cout << "File does not exist" << std::endl; 
		}	
	}
	return 0; 
}
