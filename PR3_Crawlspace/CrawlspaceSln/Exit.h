////////////////////////////////
// title: Exit.h
// descr: Refines pure virtual class Object to define an exit from a room
//		  by pairing a name with a room number to which this exit will take
//		  the explorer. This class works best if Crawlspace contains a vector
//		  of Location objects, where the index in the vector corresponds to the
//		  room number.
//
// takeme() displays an appropriate message
// depending on whether this is an exit or a treasure.
//
// Author: Iain Black
// Last updated: 10/16/2018
////////////////////////////////

#include "Object.h"

#ifndef EXIT_H_
#define EXIT_H_

class Exit : public Object {
public:
	Exit(int where_to, std::string name, std::string descr)
		: Object(name, descr, where_to) {}

	Object* takeme();

};

#endif