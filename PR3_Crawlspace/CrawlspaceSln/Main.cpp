/////////////////////////////////////
// Purpose: Test 
// Author: Iain Black
// Collaborated with Griffin Marler
///////////////////////////////////


#include <iostream>
#include <stdexcept>
#include "Exit.h"
#include "Crawlspace.h"
#include "Location.h"
#include "Object.h"
#include "Treasure.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;



int main()
{
	/////////////////////////////////////////////////////
	////// Creation of Crawlspace, locations, and objects
	Crawlspace M1;
	

	Location L0("Entrance", "The entrance to the cave is a vast chamber, there are openings in almost all directions: up, left, and right.");
	M1.addLocation(&L0);
	Exit E01(1, "Up", "There is a small crevice in the ceiling, it looks like you can climb to it.");
	M1.updateLoc(E01, 0);
	Exit E02(2, "Left", "An opening in the wall on your left leads to an unknown area.");	
	M1.updateLoc(E02, 0);
	Exit E03(3, "Right", "An opening in the wall on your right leads to an unknown location, you hear the rumbling of water in the distance.");
	M1.updateLoc(E03, 0);

	Location L1("Small Cavern", "You find yourself in a small cavern, a ray of light descends from the ceiling onto a mysterious pouch of what looks like gold.");
	M1.addLocation(&L1);
	Treasure T11("Gold", "There is a leather bag of ancient gold coins sitting upon a pedestal in the light", 100);
	M1.updateLoc(T11, 1);
	Exit E11(0, "Back", "Looks like the only way out of here is to go back to the entrance.");
	M1.updateLoc(E11, 1);

	Location L2("Large Cavern", "A long tunnel opens up into a giant cavern with an open ceiling, vegetation fills the area along with an old camp.");
	M1.addLocation(&L2);
	Treasure T21("Watch", "Within a used tent there are a number of items that someone left here, this pocket watch looks expensive..", 100);
	M1.updateLoc(T21, 2);
	Exit E21(0, "Back", "Looks like the only way out of here is to go back to the entrance.");
	M1.updateLoc(E21, 2);

	Location L3("Waterfall", "A huge underground waterfall. The walls are lit by torches, someone has definitely been here before...");
	M1.addLocation(&L3);
	Exit E31(4, "Waterfall", "Through the shimmer of the falling water you see what appears to be a wooden door placed right into the rock.");
	M1.updateLoc(E31, 3);
	Exit E32(0, "Back", "This way returns to the entrance.");
	M1.updateLoc(E32, 3);

	Location L4("Secret Room", "Upon opening the myserious door you enter a small room filled to the brim with papers, books, and charts. In the corner there is a desk covered in paper with scribbling that you cant decipher, laying face down on the desk is a skeleton...in his hand he clutches what looks like a treasure map.");
	M1.addLocation(&L4);
	Treasure T41("Map", "An old map of the carribbean with a big red X on an unmarked island.", 500);
	M1.updateLoc(T41, 4);
	Exit E41(3, "Back", "This way goes back to the waterfall room.");
	M1.updateLoc(E41, 4);
	Exit E42(5, "End", "Going this way ends the game trial.");
	M1.updateLoc(E42, 4);

	Location L5("End of Game Trial", "End of Game Trial");
	M1.addLocation(&L5);


	M1.setStart(0,5);				// sets starting location to 0 and size to 5
	M1.setCurrentLocation(0);		// sets current location to 0
	

	///////////////////////////////////////////////////
	////////////////// Game Loop //////////////////////

	// display opening dialogue
	cout << "Deep within a mediterranean jungle, you and your team of explorers have arrived at cave system said to have been a safe haven for pirates hundreds of years ago. Who knows what may lie ahead...   " << endl << "To interact with your surroundings you must type in your desired action. " << endl << "Use the 'Examine' option to observe what is around you." << endl;
	
	int endGame = 0;								
	while (endGame != -1)
	{
		std::string choice;
		Location* cur_loc = M1.getCurLoc();						// creates pointer cur_loc, points to the element within vector maze that matches the number of the current location.
																// to be used for functions accessing objects that differ depending upon location

		if (cur_loc == &L5)										// Location L5 used to end game by jumping out of game loop
		{
			cout << "Thanks for playing!" << endl;
			endGame = -1;
			break;
		}

		cur_loc->printName();
		cout << endl << "Type what you would like to do: " << endl;							
		cout << "Examine" << endl;																// Prompts user to make selection 
		cout << "Take" << endl;
		cout << "Move" << endl;
		cin >> choice;
		cout << endl;

		if (choice == "Examine")
		{
			string examineChoice;																/////Examine Option
			cout << "Please enter the name of what you would like to examine: " << endl;		// lists options once user has selected examine, including "Room" option and
			cout << "Room " << endl;															// uses list functions to display all objects
			cur_loc->listTreasures();
			cur_loc->listExits();
			cin >> examineChoice;
			cout << endl;

			cur_loc->searchExits(examineChoice);												//Use searchExits() and searchTreasure() functions to check if entered name matches
			cur_loc->searchTreasures(examineChoice);											// getName() of any object, displays description

			if (examineChoice == "Room" || examineChoice == "room")								// Room option calls description of location
				cur_loc->describe();
		}

		else if (choice == "Take")																/////Take Option
		{																						// display lists of Treasures and Exits using list functions
			string objName;
			cout << "Please enter the name of what you would like to take: " << endl;
			cur_loc->listTreasures();
			cur_loc->listExits();
			cin >> objName;
			cout << endl;

			try {
				cur_loc->find(objName);															// call find function passing user input
			}
			catch (std::exception)																//if thrown exception is caught, output appropriate message
			{
				cout << "That item isn't here!" << endl;
			}
			catch (int)
			{
				cout << "There are no more treasures to take!" << endl;								//if thrown int is caught, output appropriate message
			}
			catch (double)																		//if thrown double is caught, output appropriate message
			{
				cout << "What a concept!" << endl;
			}

		}

		else if (choice == "Move")																/////Move Option
		{
			string exitChoice;
			cout << "Please enter the name of the exit you wish to take: " << endl;
			cur_loc->listExits();																// lists available exits using list function
			cin >> exitChoice;
			cout << endl;

			try {
				M1.setCurrentLocation(cur_loc->exitLocation(exitChoice));						// uses exitLocation() to return location number of destination, sets current location to that number 
			}
			catch (std::exception)
			{
				cout << "You can't move that way! Please enter the name of a listed exit (capitals included)." << endl;		// catch thrown exception, output appropriate message
			}
		}
		else
			cout << "Not a valid option (check capitalization)." << endl;						// User input doesnt match any of three options, restarts loop

	}

	return 0;
}