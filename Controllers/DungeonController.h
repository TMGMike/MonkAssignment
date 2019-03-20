//
// Created by Mike on 09/03/2019.
//

#ifndef MONKASSIGNMENT_DUNGEONCONTROLLER_H
#define MONKASSIGNMENT_DUNGEONCONTROLLER_H

// Controller Dependencies
#include "MonsterController.h"
#include "LogController.h"

// Model Dependencies
#include "../Models/PlayerModel.h"
#include "../Models/MonsterModel.h"

// Room Dependencies
#include "../MonsterRoom.h"
#include "../EmptyRoom.h"
#include "../TreasureRoom.h"
#include "RandomController.h"

class DungeonController {
public:
    DungeonController(string playerName, string description);
    void increaseRoomCount() { roomsExplored ++; }
    int getRoomCount() { return roomsExplored; }
    void GenerateRoom(Room*);
    void BeginCombat();
    int rngRoomId();
private:
    MonsterController* monsterController;
    PlayerController* playerController;
    MonsterModel* monsterModel;
    LogController* logController;
    MonsterRoom* monsterRoom;
    RandomController* randomController;
    int roomsExplored;

    int treasureChance  = 5;
    int emptyChance     = 33;
    int monsterChance   = 62;

    Room* currentRoom;
};

#endif //MONKASSIGNMENT_DUNGEONCONTROLLER_H
