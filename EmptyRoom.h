//
// Created by Mike on 10/03/2019.
//

#ifndef MONKASSIGNMENT_EMPTYROOM_H
#define MONKASSIGNMENT_EMPTYROOM_H

#include "Controllers/PlayerController.h"
#include "Room.h"

class EmptyRoom : public Room {
public:
    EmptyRoom(Room*);
    void generate() override;
    bool hasPrayed; // Has the player prayed in the room already? Default to false.
    void pray(PlayerController* player);
    bool hasItem;
    int rngItemGen(int,int);
    void render(PlayerController*) override;
};

#endif //MONKASSIGNMENT_EMPTYROOM_H
