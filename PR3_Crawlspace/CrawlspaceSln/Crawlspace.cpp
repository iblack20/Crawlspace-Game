#include "Crawlspace.h"

void Crawlspace::addLocation(Location* l)
{
	maze.push_back(l);
}

void Crawlspace::updateLoc(Exit & e, int loc)
{
	maze[loc]->dig(e);
}

void Crawlspace::updateLoc(Treasure & t, int loc)
{
	maze[loc]->drop(t);
}
