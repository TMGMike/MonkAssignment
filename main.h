//
// Created by Mike on 09/03/2019.
//

#ifndef MONKASSIGNMENT_MAIN_H
#define MONKASSIGNMENT_MAIN_H

#include <string>
#include "Controllers/DungeonController.h"
using namespace std;

class MainView {
public:
    void startGame(string playerName, string description);

private:
    DungeonController* dungeonController;
};

#endif //MONKASSIGNMENT_MAIN_H
