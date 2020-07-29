#include "Carrier.h"

Carrier::Carrier(string name, int maxBays)
{
	this->name = name;
	this->maxBays = maxBays;
	numFighters = 0;
	bayList[maxBays];
}

bool Carrier::loadFighter(Fighter* nFighter)
{
	if (maxBays > numFighters)
	{
		bayList[numFighters] = nFighter;
		numFighters += 1;
		return true;
	}
	return false;
}

Fighter* Carrier::launchNextFighter()
{
	if (hasFighters())
	{
		numFighters--;
		Fighter* nextFighter = bayList[numFighters];
		bayList[numFighters] = nullptr;
		return nextFighter;
	}
	else
		return false;
}

string Carrier::getInfo()
{
	string info = name += "\n";
	for (int i = 0; i < numFighters; i++)
	{
	//	name += bayList[i].getInfo() + "\n";
	}
	return info;
}

bool Carrier::hasFighters()
{
	return (numFighters > 0);
}

int Carrier::getCapacity()
{
	return maxBays;
}

int Carrier::getNumFighters()
{
	return numFighters;
}

string Carrier::getName()
{
	return name;
}
