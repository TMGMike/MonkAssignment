//
// Created by Mike on 08/03/2019.
//

#include "MonsterController.h"
#include <list>

MonsterController::MonsterController(int monsterId) {
    _model = new MonsterModel();

    // Randomise the monster type. 0 = Troll, 1 = Zombie, 2 = Vampire.
    // Troll: Health = 4, Attack = 2, Defence = 3
    // Zombie: Health = 3, Attack = 4, Defence = 1
    // Vampire: Health = 3, Attack = 2, Defence = 4

    switch(monsterId) {
        case(0):
            _model->setName("Troll");
            _model->setHealth(4);
            _model->setAttack(2);
            _model->setIntroductionNoise("Groan!");
            break;
        case(1):
            _model->setName("Zombie");
            _model->setHealth(3);
            _model->setAttack(4);
            _model->setIntroductionNoise("Blurrrrrghhh!");
            break;
        case(2):
            _model->setName("Vampire");
            _model->setHealth(3);
            _model->setAttack(2);
            _model->setIntroductionNoise("Mwuahahahaha!");
            break;
        default:
            _model->setName("Troll");
            _model->setHealth(4);
            _model->setAttack(2);
            _model->setIntroductionNoise("Groan!");
            break;
    }
}

int MonsterController::getMonsterHealth() {
    return _model->getHealth();
}

string MonsterController::getMonsterName() {
    return _model->getName();
}

string MonsterController::getMonsterNoise() {
    return _model->getIntroductionNoise();
}
