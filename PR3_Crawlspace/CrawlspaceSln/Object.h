////////////////////////////////
// title: Object.h
// descr: Pure virtual superclass for Exit and Treasure
//
// describeme() displays the object name and verbose description
// pure virtual function takeme() displays an appropriate message
// depending on whether this is an exit or a treasure.
//
// Author: Iain Black
// Last updated: 10/16/2018
////////////////////////////////

#include <string>
#include <iostream>
#ifndef OBJECT_H_
#define OBJECT_H_

class Object {
private:
	std::string name;
	std::string descr;
	int value; //For exits, this will be where it takes you. For treasures, it's point value.
public:
	Object(std::string name = "Thingy",
		std::string descr = "The thingy is nondescript.",
		int value = -1) : name(name), descr(descr), value(value) {}

	void describeme() { std::cout << descr << std::endl; }

	void printName() { std::cout << name << std::endl; }

	std::string getName() { return name; }

	int getValue() { return value; }

	virtual Object* takeme() = 0;
};

#endif