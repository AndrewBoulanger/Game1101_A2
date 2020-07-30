
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

Carrier** Load2Ships(string path)
{
    Carrier** ships = new Carrier*[2];
    ifstream read;
    string name;
    int m, n, numShips;

    read.open("shipData.txt");
    if (read.is_open())
    {
        for (int i = 0; i < 2; i++)
        {
            read >> name >> m >> numShips;
            ships[i] = new Carrier(name, m);
            for (int j = 0; j < numShips; j++)
            {
                read >> name >> m >> n;
                ships[i]->loadFighter(new Fighter(name, m, n));
            }
        }
        read.close();
    }
    else
        cout << "couldn't open file\n";
     return ships;
}

int main()
{
    srand((unsigned)time(0));

    //load carriers
    Carrier *c1, *c2;
    Carrier** ships = Load2Ships("shipData.txt");
    c1 = ships[0];
    c2 = ships[1];

    //print ship info
    cout << c1->getInfo();
    cout << c2->getInfo();
    system("pause");

    //battle
    battle(c1, c2);

    //print ship info
    cout << c1->getInfo();
    cout << c2->getInfo();

}

