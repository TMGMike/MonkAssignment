//
// Created by Mike on 09/03/2019.
//
#include <random>
#include <iostream>
#include <new>
#include "MonsterRoom.h"

MonsterRoom::MonsterRoom(Room *sender) : Room (sender){

}

void MonsterRoom::generate() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 2); // define the range

    int monsterId = distr(eng);

    monster = new MonsterController(monsterId);
}

MonsterController *MonsterRoom::getMonster() {
    return monster;
}

void MonsterRoom::render(PlayerController* player) {
    if(monster->getMonsterName() == "Goblin"){
        std::cout << "                   (    )\n"
                     "                  ((((()))\n"
                     "                  |o\\ /o)|\n"
                     "                  ( (  _')\n"
                     "                   (._.  /\\__\n"
                     "                  ,\\___,/ '  ')\n"
                     "    '.,_,,       (  .- .   .    )\n"
                     "     \\   \\\\     ( '        )(    )\n"
                     "      \\   \\\\    \\.  _.__ ____( .  |\n"
                     "       \\  /\\\\   .(   .'  /\\  '.  )\n"
                     "        \\(  \\\\.-' ( /    \\/    \\)\n"
                     "         '  ()) _'.-|/\\/\\/\\/\\/\\|\n"
                     "             '\\\\ .( |\\/\\/\\/\\/\\/|\n"
                     "               '((  \\    /\\    /\n"
                     "               ((((  '.__\\/__.')\n"
                     "                ((,) /   ((()   )\n"
                     "                 \"..-,  (()(\"   /\n"
                     "                  _//.   ((() .\"\n"
                     "          _____ //,/\" ___ ((( ', ___\n"
                     "                           ((  )\n"
                     "                            / /\n"
                     "                          _/,/'\n"
                     "                        /,/,\"\n"
                     "\n"
                     "------------------------------------------------\n" << endl;
    }
    else if(monster->getMonsterName() == "Vampire"){
        std::cout << "\n"
                     "                            __...---^^^^^---...__\n"
                     "                       _.-^^                     ^^-._\n"
                     "                     ./'                             `\\.\n"
                     "                   _/'                                 `\\_\n"
                     "                  /'                                     `\\\n"
                     "                 /                                         \\\n"
                     "                |'                                         `|\n"
                     "              __'                                           `__\n"
                     "     ____.---^^^^-.                                       .-^^^^---.____\n"
                     "\\_  (   __,--^^-._ ^.                                   .^ _.-^^--.__   )  _/\n"
                     " `\\_ `-^      |  `\\  \\                                 /  /'  |      ^-' _/'\n"
                     " |\\`\\_        |    \\  \\                               /  /    |        _/'/|\n"
                     "|`|`\\`\\_     .|     \\  \\              .              /  /     |.     _/'/'|'|\n"
                     "| |  `\\`\\_   |'     |   \\             |             /   |     `|   _/'/'  | |\n"
                     "`|    /`\\`\\ ||                        |                        || /'/'\\    |'\n"
                     " |  :'   \\,|'                  .._         _..                  `|.'   `:  |\n"
                     " `| |     /                       ^=._ _.=^                       \\     | |'\n"
                     "  |      d^^^xxx.__                  `|'                  __.xxx^^^b      |\n"
                     "  `|    d#.  9XX^^\\\\^^--..__          |          __..--^^//^^XX    #b    |'\n"
                     "   |   |##x__  |    \\       ^^Xx..__  |  __..xX^^       /    |  __x#|    |\n"
                     "    \\     ^^   |     \\_            _/^ ^\\_            _/     |   ^^     /\n"
                     "     `-._      |       ^^-----...-^       ^-...-----^^      |'      _.-'\n"
                     "         ^-._  `|   ^^-------^^^^    |      ^^^^-------^^   |   _.-^\n"
                     "             ^- ||                  .|                     || -^\n"
                     "               |^||                 l|                    ||^|\n"
                     "               |  |                .d|xx.                 |  |\n"
                     "              |'  `|                                     |'  `|\n"
                     "              |   |;               ..----.               ;|   |\n"
                     "              |   |X\\._            ^ __               _./X|   |\n"
                     "             |'    |  ^-._         .X\"\"^^^         _.-^  |    `|\n"
                     "             |     |     \\^-._                 _.-^/     |     |\n"
                     "         ___|,     `|      `\\\\^-._         _.-^//'      |'     `|___\n"
                     "..---^^^^   |       |         `\\\\\\^-.___.-^///'         |       |   ^^^^---..\n"
                     "            |       `|            `\\\\XXX//'            |'       |\n"
                     "            |      | `|              ^^^              |' |      |\n"
                     "            `|     `| `|                             |' |'     |'\n"
                     "                     \\  \\                           /  /\n"
                     "..........------------------.....__      __.....-------------------..........\n"
                     "                                   ^\\   /^\n"
                     "                                     \\v/\n"
                     "                                      |\n"
                     "                                      |\n"
                     "___                                   |                                    __\n"
                     "#######xxxxxx_____                    |                    _____xxxxxx#######\n"
                     "#######################xxxxxxxxxx___  |  ___xxxxxxxxxx#######################\n"
                     "#############################################################################\n"
                     "#############################################################################\n"
                     "#############################################################################\n"
                     "#############################################################################\n"
                     "\n"  << endl;
    }
    if(monster->getMonsterName() == "Zombie"){
        std::cout << "X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n"
                     "|                           ,,'``````````````',,                            |\n"
                     "X                        ,'`                   `',                          X\n"
                     "|                      ,'                         ',                        |\n"
                     "X                    ,'          ;       ;          ',                      X\n"
                     "|       (           ;             ;     ;             ;     (               |\n"
                     "X        )         ;              ;     ;              ;     )              X\n"
                     "|       (         ;                ;   ;                ;   (               |\n"
                     "X        )    ;   ;    ,,'```',,,   ; ;   ,,,'```',,    ;   ;               X\n"
                     "|       (    ; ',;   '`          `',   ,'`          `'   ;,' ;              |\n"
                     "X        )  ; ;`,`',  _--~~~~--__   ' '   __--~~~~--_  ,'`,'; ;     )       X\n"
                     "|       (    ; `,' ; :  /       \\~~-___-~~/       \\  : ; ',' ;     (        |\n"
                     "X  )     )   )',  ;   -_\\  o    /  '   '  \\    o  /_-   ;  ,'       )   (   X\n"
                     "| (     (   (   `;      ~-____--~'       '~--____-~      ;'  )     (     )  |\n"
                     "X  )     )   )   ;            ,`;,,,   ,,,;',            ;  (       )   (   X\n"
                     "| (     (   (  .  ;        ,'`  (__ '_' __)  `',        ;  . )     (     )  |\n"
                     "X  )     \\/ ,\".). ';    ,'`        ~~ ~~        `',    ;  .(.\", \\/  )   (   X\n"
                     "| (   , ,'|// / (/ ,;  '        _--~~-~~--_        '  ;, \\)    \\|', ,    )  |\n"
                     "X ,)  , \\/ \\|  \\\\,/  ;;       ,; |_| | |_| ;,       ;;  \\,//  |/ \\/ ,   ,   X\n"
                     "|\",   .| \\_ |\\/ |#\\_/;       ;_| : `~'~' : |_;       ;\\_/#| \\/| _/ |.   ,\"  |\n"
                     "X#(,'  )  \\\\\\#\\ \\##/)#;     :  `\\/       \\/   :     ;#(\\##/ /#///  (  ',)# ,X\n"
                     "|| ) | \\ |/ /#/ |#( \\; ;     :               ;     ; ;/ )#| \\#\\ \\| / | ( |) |\n"
                     "X\\ |.\\\\ |\\_/#| /#),,`   ;     ;./\\_     _/\\.;     ;   `,,(#\\ |#\\_/| //.| / ,X\n"
                     "| \\\\_/# |#\\##/,,'`       ;     ~~--|~|~|--~~     ;       `',,\\##/#| #\\_// \\/|\n"
                     "X  ##/#  #,,'`            ;        ~~~~~        ;            `',,#  #\\##  //X\n"
                     "|####@,,'`                 `',               ,'`                 `',,@####| |\n"
                     "X#,,'`                        `',         ,'`                        `',,###X\n"
                     "|'                               ~~-----~~                               `' |\n"
                     "X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n"
                     "\n"
                     "------------------------------------------------\n" << endl;
    }

    cout << "You enter a dark room, you can hardly see. In front of you, you hear a " << monster->getMonsterNoise() << endl;
    cout << "It's a " << monster->getMonsterName() << "! The door behind you locks. The battle has already begun." << endl;

    int turn = 0; // 0 = The next turn in combat. Player's turn, 1 = Monster's turn.
    while(monster->getMonsterHealth() > 0) {

        printf("The monster's health is currently: [%d / %d]\n", monster->getMonsterHealth(), monster->getMonsterBaseHealth());
        printf("The Monk's Health is currently: [%d / %d]\n", player->getPlayerHealth(), player->getPlayerBaseHealth());

        if(turn == 0) {
            string instruction = "2";

            while(instruction != "0" && instruction != "1"){
                cout << "What will the all-powerful Monk do? \n [0] = Attack \n [1] = Defend\n";
                cin >> instruction;
                if(instruction != "0" && instruction != "1") {
                    cout << "The Monk didn't understand this instruction!" << endl;
                }
            }

            if(instruction == "0") {
                player->tryFight(monster);
            }
            else {
                player->tryDefend(monster);
            }

            turn = 1; // Set the turn to the monster.
        }
        else {

            if (monster->tryAction()) { // Tries to attack or defend
                if(monster->actionToPerform() == 0) {
                    if(player->playerHasProtection()) {
                        cout << "\n The " << monster->getMonsterName() << "tried to attack, but the Staff of Protection blocked the attack from the " << monster->getMonsterName() << "!" << endl;
                        player->setPlayerProtection(false);
                    } else {
                        cout << "\nThe " << monster->getMonsterName() << " strikes " << player->getPlayerName() << " the Monk! OUCH!" << endl;
                        player->subtractPlayerHealth(monster->getMonsterAttackPoints());
                    }
                }
                else if (monster->getMonsterHealth() != monster->getMonsterBaseHealth()){
                    monster->setMonsterHealth(monster->getMonsterHealth() + 1);
                    cout << "\nThe " << monster->getMonsterName() << " defended against " << player->getPlayerName() << " the Monk and gained +1 health." << endl;
                }
                else {
                    cout << "\nThe " << monster->getMonsterName() << " defended itself, but was already full health." << endl;
                }
            }
            else if (monster->actionToPerform() == 1) { // The monster failed their action. If it was defending, they should lose health. If it was attack, it is ignored since nothing happened.
                monster->subtractMonsterHealth(player->getPlayerDamage());
                cout << "\nThe " << monster->getMonsterName() << " failed to defend itself, and " << player->getPlayerName() << " exploited this!" << endl;
            }
            else {cout << "\nThe " << monster->getMonsterName() << " failed to attack " << player->getPlayerName() << " the Monk!" << endl; }

            turn = 0; // Set the turn back to the player.
        }
    }

    cout << "The " << monster->getMonsterName() << " was defeated by " << player->getPlayerName() << " The Monk! \n The Monk moves on to the next room..." << endl;
    delete monster;

    isRoomComplete = true;

    string direction = "_";

    while(direction != "0" && direction != "1") {
        cout << "Which way does " << player->getPlayerName() << " go?\n [0] = Left \n [1] = Right \n";
        cin >> direction;
        if(direction != "0" && direction != "1") {
            cout << "The Monk realises this isn't a direction..." << endl;
        }
    }
}

bool MonsterRoom::isMonsterAlive() {
    return (monster->getMonsterHealth() > 0);
}
