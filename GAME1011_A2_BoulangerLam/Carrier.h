#pragma once

#include <string>
#include <sstream>
#include "Fighter.h"
using namespace std;

class Carrier
{
private:
	string name;
	int maxBays, numFighters;
	Fighter** bayList;

public:
	Carrier() = default;
	Carrier(string name, int maxBays);

	bool loadFighter(Fighter* nFighter);
	Fighter* launchNextFighter();

	string getInfo();
	bool hasFighters();
	int getCapacity();
	int getNumFighters();
	string getName();
};

