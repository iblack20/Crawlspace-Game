////////////////////////////////
// title: Treasure.h
// descr: Refines pure virtual class Object to define a treasure.
//
// takeme() displays an appropriate message and returns a pointer
// to the treasure to allow it to be put in inventory.
//
// Author: Iain Black
// Last updated: 10/17/2018
////////////////////////////////

#include "Object.h"
#ifndef TREASURE_H_
#define TREASURE_H_

class Treasure : public Object {
public:
	Treasure(std::string name, std::string descr, int value) :
		Object(name, descr, value) {}

	Object* takeme();

};

#endif