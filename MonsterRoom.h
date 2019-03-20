//
// Created by Mike on 09/03/2019.
//

#ifndef MONKASSIGNMENT_MONSTERROOM_H
#define MONKASSIGNMENT_MONSTERROOM_H

#include "Room.h"
#include "Controllers/MonsterController.h"

class MonsterRoom : public Room {
public:
    MonsterRoom(Room*);
    void generate() override;
    MonsterController* getMonster();
    void render(PlayerController*) override;
    bool isMonsterAlive() override;
private:
    MonsterController *monster;
};


#endif //MONKASSIGNMENT_MONSTERROOM_H
