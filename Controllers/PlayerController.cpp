//
// Created by Mike on 15/03/2019.
//
#include <iostream>
#include <random>

#include "PlayerController.h"

using namespace std;

/**
 * Initialise the Player object, as well as the data model, and set some basic values.
 * @param attack Sets the players Attack points dealt to monsters during combat.
 * @param playerName The Player's name which is provided when the game starts
 * @param playerDescription The description of the Monk, provided by the player at the start.
 */
PlayerController::PlayerController(int attack, string playerName, string playerDescription) {
    this->player = new PlayerModel(attack, playerName, playerDescription); // Initialise the player Model
}
/**
 * Get the player's current health points
 * @return Integer representing the player's current health
 */
int PlayerController::getPlayerHealth() {
    return player->getHealth();
}
/**
 * Override the player's current health to a provided integer.
 * @param value The value to set the player's health to.
 */
void PlayerController::setPlayerHealth(int value) {
    player->setHealth(value);
}
/**
 * Subtract some health from the player's current health.
 * @param value The amount of health points to subtract from the player's health.
 */
void PlayerController::subtractPlayerHealth(int value) {
    player->setHealth(player->getHealth() - value);
    if(player->getHealth() < 1) {
        Die();
    }
}

/**
 * Gets the description of the Monk, which is provided when the game starts.
 * @return The description of the Monk.
 */
string PlayerController::getPlayerDescription() {
    return player->getDescription();
}

/**
 * Gets the name of the player, which was provided when the game started.
 * @return A string representing the player's name.
 */
string PlayerController::getPlayerName() {
    return player->getName();
}

/**
 * The Base Health is the maximum health that the player starts the game with.
 * @return Integer representing the maximum health of the player.
 */
int PlayerController::getPlayerBaseHealth() {
    return player->getBase();
}

/**
 * Gets the player's damage from the model.
 * @return An integer of the player's damage points.
 */
int PlayerController::getPlayerDamage() {
    return player->getDamage();
}

/**
 * Try to complete an action, such as attacking or defending from a monster.
 * tryAction generates a number between 0 or 1, determining whether the action attempted was successful.
 * 0 = unsuccessful
 * 1 = successful
 *
 * @return Boolean of whether the action was successful or not.
 */
bool PlayerController::tryAction() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 1); // define the range

    int actionInt = distr(eng);
    return (actionInt == 1);
}

/**
 * The combat attack behaviour for the player. If the action is successful, the player will damage the monster.
 * If the action is unsuccessful, the Monk will deal no damage.
 * @param monster The Monster's Controller object currently in combat against the player.
 */
void PlayerController::tryFight(MonsterController *monster) {
    if(tryAction()) {
        cout << getPlayerName() << " the Monk attacks the " << monster->getMonsterName() << "!" << endl;
        monster->subtractMonsterHealth(getPlayerDamage());
    }
    else {
        cout << "The " << monster->getMonsterName() << " dodged " << getPlayerName() << "'s attack!" << endl;
    }
}

/**
 * The combat defend behaviour for the player. If the action is successful, the player will restore 1 HP.
 * If the action is unsuccessful, the player will gain no health points, and the monster will be able to attack.
 */
void PlayerController::tryDefend(MonsterController *monster) {
    if(tryAction()) {
        cout << endl;
        cout << getPlayerName() << " the Monk defends themselves against the monster, restoring 1 HP." << endl;

        // If the player does not have max health, increase it by 1. Otherwise, move on.
         if(getPlayerHealth() != getPlayerBaseHealth()) setPlayerHealth(getPlayerHealth() + 1);
    }
    else {
        cout << endl;
        cout << getPlayerName() << " the Monk failed to defend against the " << monster->getMonsterName() << endl;
        cout << "The " << monster->getMonsterName() << " dealt ";
        printf("%d damage!\n", monster->getMonsterAttackPoints());

        subtractPlayerHealth(monster->getMonsterAttackPoints());
    }
}

void PlayerController::setPlayerProtection(bool toggle) {
    player->hasProtection = toggle;
}

bool PlayerController::playerHasProtection() {
    return player->hasProtection;
}

void PlayerController::Die() {
    cout << getPlayerName() << " died in battle! The treasure was never found..." << endl;
    system("pause");
    exit(0);
}

