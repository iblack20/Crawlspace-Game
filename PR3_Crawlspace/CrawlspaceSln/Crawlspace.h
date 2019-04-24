////////////////////////////////
// title: Crawlspace.h
// descr: Defines a Crawlspace as a vector of locations
//		  Goal is for an Explorer to be able to traverse
//		  a maze of locations collecting treasures.
//
// Author:Iain Black 
// Last updated: 10/18/2018
////////////////////////////////

#include<vector>
#include "Location.h"

#ifndef CRAWLSPACE_H_
#define CRAWLSPACE_H_

class Crawlspace {
private:
	std::vector<Location *> maze;
	unsigned short start; // The starting location for the maze
	unsigned short size;  // The total number of locations in this maze.
	int current_location; // current location that player is in 
public:
	//When a Crawlspace is first constructed, its starting location is -2 and its size is 0.
	//i.e. there are no locations. 
	Crawlspace() : start(-1), size(0) {}

	//Useful functions for designing and creating a Crawlspace:
#pragma region Design
	/*****************************
	* Adds a location to the crawlspace
	* @param l is a reference to a location.
	* Postcondition: a new location is added to the crawlspace
	******************************/
	void addLocation(Location* l);

	/*****************************
	* Adds an exit to an existing location
	* @param e is an exit
	* @param loc is the location to which an exit is being added
	* Postcondition: a new exit is added to the crawlspace
	******************************/
	void updateLoc(Exit& e, int loc);

	/*****************************
	* Drops a treasure into an existing location
	* @param t is an treasure
	* @param loc is the location into which t is being dropped
	* Postcondition: a new treasure is added to the crawlspace
	******************************/
	void updateLoc(Treasure& t, int loc);

	//Sets a new start location. The location must already be in locations, and
	//we must know where it is in the vector.
	void setStart(unsigned short startLoc, unsigned short newSize) { start = startLoc; size = newSize; }

	////new function
	// Sets current_location
	void setCurrentLocation(int loc) { current_location = loc; }

	////new function
	// returns number of current location according to place in vector maze
	Location *  getCurLoc() {return maze[current_location]; }
#pragma endregion
};

#endif