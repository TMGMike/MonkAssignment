//
// Created by Mike on 09/03/2019.
//
#include <iostream>
#include <random>
#include "DungeonController.h"

DungeonController::DungeonController(string playerName, string description) {
    playerController = new PlayerController(3, playerName, description);
    logController = new LogController();
    randomController = new RandomController;

    logController->clearLogs();
    logController->log("Monk created with name: " + playerName + " with a base health of 15, and a damage of 3.");
    logController->log("Monk's description: " + description);

    EmptyRoom* spawnRoom = new EmptyRoom(nullptr);

    spawnRoom->generate();
    spawnRoom->render(playerController);

    GenerateRoom(spawnRoom);
}



void DungeonController::GenerateRoom(Room *sender) {
    roomsExplored++;
    cout << playerController->getPlayerName() << " The Monk has explored ";
    printf("%d rooms in the dungeon. \n", roomsExplored);
    /*
       Set the chance of finding a treasure gradually higher, and the chance of finding an empty room to heal lower.
       This behaviour should encourage an end-game. Whether it be defeat due to a lower chance of healing, or win if
       the treasure room is found. This prevents the game from running for too long.
    */
    if(roomsExplored > 10) {
        treasureChance = 40;
        emptyChance = 13;
        monsterChance = 47;
    }
    else if(roomsExplored > 5) {
        treasureChance = 15;
        monsterChance = 55;
    }
    int roomId = rngRoomId();
    Room* newRoom;


    logController->log("Generating new room....");
    switch (roomId){
        default:
        case (0):
            newRoom = new EmptyRoom(sender);
            newRoom->generate();
            currentRoom = newRoom;
            logController->log("Generated new Empty room");
            break;
        case (1):
            newRoom = new MonsterRoom(sender);
            newRoom->generate();
            logController->log("Generated new Monster room");
            break;
        case(2):
            TreasureRoom* treasureRoom = new TreasureRoom(sender);
            treasureRoom->generate();

            currentRoom = treasureRoom;

            treasureRoom->render(playerController->getPlayerName());
            logController->log("Generated Treasure room!");

            break;
    }
    currentRoom = newRoom;

    if(!newRoom->isTreasureRoom()) {
        newRoom->render(playerController);
        logController->log("Room was not a treasure room, generating another...");
        GenerateRoom(newRoom);
    } else {
        logController->log("Generated treasure room! Stopped generating new rooms");
    }
}

/**
 * Generate a random room ID.
 * 0 = Empty Room
 * 1 = Monster Room
 * 2 = Treasure Room
 *
 * @return The room ID which was generated here.
 */
int DungeonController::rngRoomId() {
    int roomChance = randomController->getRandomIndex(1,100);
    if(roomChance < treasureChance) {
        return 2;
    }
    else if (roomChance < emptyChance) {
        return 0;
    }
    else {
        return 1;
    }
}

void DungeonController::BeginCombat() {
    while(currentRoom->isMonsterAlive()) {

    }
}

