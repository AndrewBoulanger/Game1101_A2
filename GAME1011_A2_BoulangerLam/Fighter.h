#pragma once
#include <string>
using namespace std;
class Fighter
{
private:
	string fName;
	int damage;
	int structStrength;
public:
	Fighter(string name, int damage, int str);
	void reduceStructure(int damage);
	string getFName();
	int getDamage();
	int getStructStrength();
	string getInfo();
};