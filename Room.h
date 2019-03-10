//
// Created by Mike on 08/03/2019.
//
#pragma once

#ifndef MONKASSIGNMENT_ROOM_H
#define MONKASSIGNMENT_ROOM_H

#include "Controllers/MonsterController.h"
using namespace std;
class Room {
protected:
    Room();
    Room(Room *);
    virtual void generate(){};
    virtual void setEnteredFrom(Room *previousRoom); // Set the exit to the previous room.
    virtual void render(){};
    Room *getLeftRoom();
    Room *getRightRoom();
    void setLeftRoom(Room *left);
    void setRightRoom(Room *right);

private:
    Room* enteredFrom;
    Room* leftDoor;
    Room* rightDoor;
};
/*

class EmptyRoom {
public:
    EmptyRoom();
private:
};

class MonsterRoom {
public:
    MonsterRoom(MonsterController* monster);
    MonsterController * getMonster();

private:
    MonsterController* monster;
};

class TreasureRoom {
public:
    bool collected;

private:

};
*/

#endif //MONKASSIGNMENT_ROOM_H
