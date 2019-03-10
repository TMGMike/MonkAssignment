//
// Created by Mike on 09/03/2019.
//

#ifndef MONKASSIGNMENT_PLAYERMODEL_H
#define MONKASSIGNMENT_PLAYERMODEL_H

#include <string>
using namespace std;

class PlayerModel {
public:
    PlayerModel(int baseHealth, int baseDamage, const string &playerName, const string &description);

    const string &getName() const;

    void setName(const string &name);

    const string &getDescription() const;

    void setDescription(const string &description);

private:
    int health;
    int damage;
    string name;
    string description;
};


#endif //MONKASSIGNMENT_PLAYERMODEL_H
