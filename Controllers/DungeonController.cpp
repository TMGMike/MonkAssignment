//
// Created by Mike on 09/03/2019.
//
#include <iostream>
#include "DungeonController.h"

DungeonController::DungeonController(string playerName, string description) {
    roomController = new RoomController();
    playerModel = new PlayerModel(15, 3, playerName, description);
    logController = new LogController();
    monsterRoom = new MonsterRoom(monsterRoom);
    logController->clearLogs();
    logController->log("Monk created with name: " + playerName + " with a base health of 15, and a damage of 3.");
    logController->log("Monk's description: " + description);

    monsterRoom->generate();
    monsterRoom->render();
}

void DungeonController::TreasureCollected() {
    cout << playerModel->getName() << " The Monk collected the treasure, and makes their way out of the dungeon!";
    string ignored;
    cin >> ignored;
}