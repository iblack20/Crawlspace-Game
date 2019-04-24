#include <stdexcept>
#include "Location.h"

int Location::exitLocation(std::string name)
{
	std::list<Exit>::iterator cur = exits.begin();
	while (cur != exits.end()) {
		if (cur->getName() == name) // found it!							// checks if user input matches member of list exits, if so returns getValue() holding location number of
			return cur->getValue();											// desired destination 
																			
		++cur;
	}

	//Otherwise, we didn't find it
	throw std::exception("Please enter the name of a valid exit.");			// if loop completes meaning no matches were found, throws exception because no valid exit was entered
}

Object* Location::find(std::string name)
{
	Object* item = nullptr;
	std::list<Treasure>::iterator cur = inventory.begin();
	while (cur != inventory.end()) {										// checks if user input matches member of list inventory, if so calls takeme() function and deletes member from list
		if (cur->getName() == name) { // Found it!
			item = cur->takeme();
			inventory.erase(cur); // No longer here
			break;
		}
		if (name != cur->getName())											// if user input doesnt match any members of inventory list, throws exception because
			throw std::exception("That item isn't here!");					// the user hasnt entered the name of a valid treasure
	}
	std::list<Exit>::iterator it = exits.begin();							// Searches list of exits
	while (it != exits.end()) {												// checks again if there are no matches to user input because previous while loop won't run if there are no treasures in a location
		if (name != it->getName())											// if no matches throws an int because the user has not entered the name of any valid treasure OR exit
			throw 5;
		if (name == it->getName())											// checks if user input matches any members of exit list, if so throws a double because
			throw 5.5;														// the user has tried to take an exit
	}
}

//Lists exits
///// changed
void Location::listExits()
{
	std::cout << "Exits:" << std::endl;
	std::list<Exit>::iterator it = exits.begin();
	while (it != exits.end()) {
		it->printName();											// now lists names instead of description using added printName() function
		++it;
	}
	std::cout << std::endl;
}

//List treasures in the room inventory
//// changed
void Location::listTreasures()
{
	std::cout << "Treasures:" << std::endl;
	std::list<Treasure>::iterator it = inventory.begin();
	while (it != inventory.end()) {
		it->printName();											// now lists names instead of description using added printName() function
		++it;
	}
	std::cout << std::endl;
}

////// new function
//checks if passed string matches getName of any item in exits,
// if so, calls describeme() of that object
void Location::searchExits(std::string name)
{
	std::list<Exit>::iterator it = exits.begin();
	while (it != exits.end()) {
		if (name == it->getName())									
			it->describeme();										
			
		++it;
	}

}
////// new function
//checks if passed string matches getName of any item in inventory
// if so, calls describeme() from that object
void Location::searchTreasures(std::string name)
{
	std::list<Treasure>::iterator it = inventory.begin();			
	while (it != inventory.end()) {									
		if (name == it->getName())
			it->describeme();
		++it;
	}
}

//Display the verbose description
////changed
void Location::describe()
{
	//Display only description of the setting
	std::cout << descr << std::endl;

}
