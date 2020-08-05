//Andrew Boulanger 101 292 574
//Pauleen Lam 101 065 605


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

void Load2Ships(string path, Carrier *first, Carrier *second)
{
    Carrier* ships[2] = {first, second};
    ifstream read;
    string name;
    int m, n, numShips;

    read.open("shipData.txt");
    if (read.is_open())
    {
        for (int i = 0; i < 2; i++) //for each ship
        {
            read >> name >> m >> numShips;
            *ships[i] = Carrier(name, m);

            for (int j = 0; j < numShips; j++) //for each fighter
            {
                read >> name >> m >> n;
                ships[i]->loadFighter(new Fighter(name, m, n));
            }
        }
        read.close();
    }
    else
        cout << "couldn't open file\n";

}

int main()
{
    srand((unsigned)time(0));

    //load carriers
    Carrier c1, c2;
    Load2Ships("shipData.txt", &c1, &c2);

    //print ship info
    cout << c1.getInfo();
    cout << c2.getInfo();
    system("pause");

    //battle
    battle(&c1, &c2);

    //print ship info (one will be dead)
    cout << c1.getInfo();
    cout << c2.getInfo();

}

