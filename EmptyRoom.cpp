//
// Created by Mike on 10/03/2019.
//
#include <iostream>
#include <random>
#include "EmptyRoom.h"
using namespace std;

EmptyRoom::EmptyRoom(Room *sender) : Room(sender)
{

}

void EmptyRoom::pray(PlayerController *player) {
    player->setPlayerHealth(player->getPlayerBaseHealth());
}



void EmptyRoom::generate() {
    this->hasPrayed = false;

    // Set hasItem to true if rngItemGen returns less than 20, therefore making an item a 20% chance.
    hasItem = (rngItemGen(1, 100) < 20);
}

void EmptyRoom::render(PlayerController* player) {
    cout << "You enter a room. There's a dim light in front of you. There's a circle of "
            "candles underneath the light. It looks important. ";
    // Initialise the instruction to something other than the supported options, to enter the while loop
    string instruction = "2";

    // Keep asking the player for the correct instruction. Break out of the loop when it's a 0 or 1.
    while(instruction != "0" && instruction != "1") {
        cout << "\n What would you like to do? \n [0] = pray \n [1] = move on" << endl;
        cin >> instruction;
        if(instruction != "0" && instruction != "1") { cout << "Input unrecognised :( " << endl; }
    }

    if(instruction == "0") {
        pray(player);
        printf("Naturally, you sit inside the demonic-looking summoning circle. You're now full health! [%d / %d] \n",
               player->getPlayerHealth(), player->getPlayerBaseHealth());
    }

    if(hasItem) {
        cout << "As " << player->getPlayerName() << " walks forward, they see a glisten in front of them." << endl;

        instruction = "2";
        while (instruction != "0" && instruction != "1") {
            cout << " What do you do? \n [0] = Pick Up \n [1] = Ignore" << endl;

            cin >> instruction;
            if(instruction != "0" && instruction != "1") cout << "The Monk didn't understand that!"<<endl;
        }

        if(instruction == "0") {
            if(rngItemGen(1, 100) < 21) {
                cout << "You approach the item and pick it up... It's a Staff of Protection! \n During your next combat, the Staff of Protection will block the first attack." << endl;
                player->setPlayerProtection(true);
            }
            else {
                cout << "You approach the item and pick it up... OUCH! It was a sewing needle! \n You lose 1 HP. :( " << endl;
                player->subtractPlayerHealth(1);
            }
        }
    }

    cout <<  player->getPlayerName() << " the Monk moves on to the next room..." << endl;
}

int EmptyRoom::rngItemGen(int from, int to) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(from, to); // define the range

    int actionInt = distr(eng);
    return actionInt;
}
