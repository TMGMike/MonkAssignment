//
// Created by Mike on 09/03/2019.
//

#ifndef MONKASSIGNMENT_DUNGEONCONTROLLER_H
#define MONKASSIGNMENT_DUNGEONCONTROLLER_H

// Controller Dependencies
#include "MonsterController.h"
#include "RoomController.h"
#include "LogController.h"

// Model Dependencies
#include "../Models/PlayerModel.h"
#include "../Models/MonsterModel.h"

// Room Dependencies
#include "../MonsterRoom.h"

class DungeonController {
public:
    DungeonController(string playerName, string description);
    void TreasureCollected();
private:
    RoomController* roomController;
    MonsterController* monsterController;
    PlayerModel* playerModel;
    MonsterModel* monsterModel;
    LogController* logController;
    MonsterRoom* monsterRoom;
};


#endif //MONKASSIGNMENT_DUNGEONCONTROLLER_H
