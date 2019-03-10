#include <iostream>
#include "Controllers/DungeonController.h"
#include "main.h"
int main() {
    string name, description;

    std::cout << "You're in a fractured reality. And a dungeon, don't forget that. Once you advance through a door, there's no going back. Good luck... \n \n Now that's over, what's your name?\n";
    std::getline(std::cin, name);

    std::cout << "The powerful Monk has established his name; " << name << " \n But what's his story? \n";
    std::getline(std::cin, description);

    auto * mainDungeon = new MainDungeon();

    mainDungeon->startGame(name, description);
    return 0;
}

void MainDungeon::startGame(string playerName, string description) {
    this->dungeonController = new DungeonController(std::move(playerName), std::move(description));
    dungeonController->TreasureCollected();
}
