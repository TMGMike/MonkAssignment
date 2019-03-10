//
// Created by Mike on 09/03/2019.
//
#include <random>
#include <iostream>
#include <new>
#include "MonsterRoom.h"

MonsterRoom::MonsterRoom(Room *from) : Room (from){

}

void MonsterRoom::generate() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 2); // define the range

    int monsterId = distr(eng);

    monster = new MonsterController(monsterId);
}

MonsterController *MonsterRoom::getMonster() {
    return monster;
}

void MonsterRoom::render() {
    if(monster->getMonsterName() == "Troll"){
        cout << "   -----------------------------------------------------------" << endl;
        cout << "   |                                                         |" << endl;
        cout << "   |                       -          -                      |" << endl;
        cout << "   |                                                         |" << endl;
        cout << "   |                                                         |" << endl;
        cout << "   |                     ,_____________                      |" << endl;
        cout << "   |                    /              \\                     |" << endl;
        cout << "   |                    \\--------------/                     |" << endl;
        cout << "   |                                                         |" << endl;
        cout << "   -----------------------------------------------------------" << endl;
    }
    else if(monster->getMonsterName() == "Vampire"){
        cout << "   -----------------------------------------------------------" << endl;
        cout << "   |                                                         |" << endl;
        cout << "   |                       -          -                      |" << endl;
        cout << "   |                                                         |" << endl;
        cout << "   |                                                         |" << endl;
        cout << "   |                     ,_____________                      |" << endl;
        cout << "   |                    /              \\                     |" << endl;
        cout << "   |                    \\--v-------v---/                     |" << endl;
        cout << "   |                                                         |" << endl;
        cout << "   -----------------------------------------------------------" << endl;
    }
    if(monster->getMonsterName() == "Zombie"){
        cout << "   -----------------------------------------------------------" << endl;
        cout << "   |                                                         |" << endl;
        cout << "   |                       x          x                      |" << endl;
        cout << "   |                                                         |" << endl;
        cout << "   |                                                         |" << endl;
        cout << "   |                     ,_____________                      |" << endl;
        cout << "   |                    /              \\                     |" << endl;
        cout << "   |                    \\--------------/                     |" << endl;
        cout << "   |                                                         |" << endl;
        cout << "   -----------------------------------------------------------" << endl;
    }

    cout << "You enter a dark room, you can hardly see. In front of you, you hear a " << monster->getMonsterNoise() << endl;
    cout << "It's a " << monster->getMonsterName() << "! The door behind you locks. The battle has already begun." << endl;
}