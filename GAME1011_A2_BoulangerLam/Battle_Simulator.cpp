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
int rollDice(int sides, int goal)
{
    int roll = rand() % sides + 1;
    if (goal == -1) // goal = -1 to use dice for value
    {
        if (roll == 0) return 1; // at least 1
        return roll;
    }
    else // true or false of over goal amount
    {
        if (roll >= goal) return 1;
        return 0;
    }
}

void battle(Carrier* c1, Carrier* c2)
{
    int num,
        round = 1, battle = 1;
    Fighter* f1;
    Fighter* f2;
    Fighter* first;
    Fighter* second;

    while (c1->hasFighters() && c2->hasFighters())
    {
        system("CLS");
        f1 = c1->launchNextFighter();
        f2 = c2->launchNextFighter();

        cout << "BATTLE #" << battle << " CHALLENGERS----------------------------------\n\n"
            << "---From carrier " << c1->getName() << "---------\n"
            << f1->getInfo() << ".\n"
            << "---From carrier " << c2->getName() << "---------\n"
            << f2->getInfo() << ".\n";

        system("pause");

        // main battle code
        while (f1->getStructStrength() > 0 && f2->getStructStrength() > 0) {
            cout << "------------- ROUND " << round << "------------\n";
            // see who goes first
            if (rollDice(100, 50)) {
                first = f1;
                second = f2;
            }
            else {
                first = f2;
                second = f1;
            }
            // attack
            cout << first->getFName() << " attacks first...\n";
            num = rollDice(first->getDamage(), -1);
            if (rollDice(100, 50)) {
                num = rollDice(first->getDamage(), -1);
                second->reduceStructure(num);
                cout << first->getFName() << " hits " << second->getFName() << " for " << num << " damage!!!\n";
            }
            else {
                cout << first->getFName() << " misses " << second->getFName() << "!!!\n";
            }
            /// if the defender is alive....
            if (second->getStructStrength() > 0) {
                cout << second->getFName() << " counter attacks ...\n";
                if (rollDice(100, 50)) {
                    num = rollDice(second->getDamage(), -1);
                    first->reduceStructure(num);
                    cout << second->getFName() << " hits " << first->getFName() << " for " << num << " damage!!!\n";
                }
                else {
                    cout << second->getFName() << " misses " << first->getFName() << "!!!\n";
                }
            }
            else
            {
                cout << "BOOOOOMMMM ! " << second->getFName() << " destroyed!!!!!\n";
            }
            round++;
            cout << "End of round stats: " << f1->getFName() << "(" << f1->getStructStrength() << " structure strength)\t" << f2->getFName() << "(" << f2->getStructStrength() << " structure strength)\n";
        }
        //after the battle ...
        if (f1->getStructStrength() > 0) {
            cout << endl << f1->getFName() << " is VICTORIOUS and loads back to carrier " << c1->getName() << "!!!\n";
            c1->loadFighter(f1);
        }
        else {
            cout << endl << f2->getFName() << " is VICTORIOUS and loads back to carrier " << c2->getName() << "!!!\n";
            c2->loadFighter(f2);
        }
        system("pause");

        battle++;
        round = 1;
    }

    if (c1->hasFighters())
        cout << endl << c2->getName() << " is out of fighters, the battle is over...\n\n" << c1->getName() << " WINS!\n\n";
    else
        cout << endl << c1->getName() << " is out of fighters, the battle is over...\n\n" << c2->getName() << " WINS!\n\n";

    system("pause");
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
                ships[i]->loadFighter(new Fighter(name, n, m));
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

    return 0;
}

