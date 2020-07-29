
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>

#include "Carrier.h"
#include "Fighter.h"

//roll a die of however many sides. return true if roll >= goal 
bool rollDice(int sides, int goal)
{
    int roll = rand() % sides + 1;
    return (roll >= goal);
}

void battle(Carrier* c1, Carrier* c2)
{

}

int main()
{
    srand((unsigned)time(0));

    std::cout << "Hello World!\n";
}

