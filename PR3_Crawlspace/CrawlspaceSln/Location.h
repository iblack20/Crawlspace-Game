////////////////////////////////
// title: Location.h
// descr: Defines a location object for a crawlspace.
//		  Locations have a short name and verbose description.
//		  Locations have exits that lead to other locations in
//		  in a crawlspace.
//		  Locations have an inventory of treasures that can be
//		  updated by explorers taking said treasures.
//
// Author:Iain Black
// Last updated: 10/17/2018
////////////////////////////////

#include <string>
#include <list>
#include "Exit.h"
#include "Treasure.h"

#ifndef LOCATION_H_
#define LOCATION_H_

class Location {
private:
	std::string name;
	std::string descr;
	std::list<Exit> exits;
	std::list<Treasure> inventory;

	friend class Crawlspace; // We want Crawlspace to be able to dig new exits and place treasures
	
	//Digs an exit from this location to another in the crawlspace
	void dig(Exit e) { exits.push_back(e); }

	//Drops a treasure in the location
	void drop(Treasure t) { inventory.push_back(t); }

public:
	Location(std::string name, std::string descr) : name(name), descr(descr) {}

	//Scans for an exit by name and returns the associated location number
	int exitLocation(std::string name);

	//Scans for a treasure and hands it over, removing it in the process from the loc
	Object* find(std::string name);

	//Displays only the name
	void printName() { std::cout << name << std::endl; }

	//Displays the names of all exits and treasures
	void listExits();
	void listTreasures();

	// Searches lists by name and returns description if found
	void searchExits(std::string name);
	void searchTreasures(std::string name);

	//Display the verbose description of location
	void describe();

};

#endif