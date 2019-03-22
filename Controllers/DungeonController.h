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
    void GenerateRoom(Room*, string);
    void BeginCombat();
    void BeginPuzzle();
    int rngRoomId();
    void ExploreEmptyRoom();
    void MoveRoom();
    void CombatTryAttack(MonsterRoom*, int);
    void CombatTryDefend(MonsterRoom*, int);
private:
    MonsterController* monsterController;
    PlayerController* playerController;
    MonsterModel* monsterModel;
    LogController* logController;
    MonsterRoom* monsterRoom;
    RandomController* randomController;
    int roomsExplored = 0;

    int treasureChance  = 5;
    int emptyChance     = 27;
    int monsterChance   = 58;
    int puzzleChance    = 10;

    Room* currentRoom;
};

#endif //MONKASSIGNMENT_DUNGEONCONTROLLER_H
