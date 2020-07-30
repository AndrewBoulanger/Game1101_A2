#include "Fighter.h"
#include <iostream>
using namespace std;

Fighter::Fighter(string name, int damage, int str)
{
	fName = name;
	this->damage = damage;
	structStrength = str;
}

void Fighter::reduceStructure(int damage)
{
	structStrength -= damage;
	if (structStrength < 0)
		structStrength = 0;
}

string Fighter::getFName()
{
	return fName;
}

int Fighter::getDamage()
{
	return damage;
}

int Fighter::getStructStrength()
{
	return structStrength;
}

void Fighter::getInfo()
{
	cout << "Fighter Name: " << fName << endl
		 << "Structural Strength: " << structStrength << endl
		 << "Damage: " << damage << endl;
}
