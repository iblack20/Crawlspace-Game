#include "Treasure.h"

Object * Treasure::takeme()
{
	std::cout << "You got " << this->getValue() << " points!" << std::endl;
	return this;
}
