//
// Created by Mike on 08/03/2019.
//

#ifndef MONKASSIGNMENT_MONSTERCONTROLLER_H
#define MONKASSIGNMENT_MONSTERCONTROLLER_H

#include "../Models/MonsterModel.h"

class MonsterController {
public:
    MonsterController(int monsterId);
    int getMonsterHealth();
    string getMonsterName();
    string getMonsterNoise();
private:
    MonsterModel* _model;
};


#endif //MONKASSIGNMENT_MONSTERCONTROLLER_H
