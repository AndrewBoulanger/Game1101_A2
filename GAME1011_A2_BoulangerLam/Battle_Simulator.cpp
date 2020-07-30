
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>

#include "Carrier.h"
#include "Fighter.h"

//roll a die of however many sides. returns true if roll >= goal 
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

    Carrier* a1 = new Carrier("titanic", 2);
    Fighter* f1 = new Fighter("doug", 2, 6);

    a1->loadFighter(f1);
   
    cout << a1->getInfo();

    std::cout << "Hello World!\n";
}

