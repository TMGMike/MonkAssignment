# Monk Assignment
## Object-Oriented Systems Development
*My C++ Assignment for the Object-Oriented Systems Development module*. 

A dungeon game where the player plays as a Monk, travelling through the dungeon with randomly generated rooms. They must get to the Treasure Room to win, without dying to monsters.

### Rooms

There are currently the following room types:
- MonsterRoom - Spawns a random monster, which the player must defeat before advancing.
- EmptyRoom - The player is allowed to pray in order to restore HP, or just move on. This room can *also* spawn an item (50% chance). If it does spawn an item, the item spawned is also random. It can be a Staff of Protection, which blocks the monster's first attack, or a sewing needle to subtract HP.
- TreasureRoom - The player can collect the treasure to win the game.
- PuzzleRoom - the player can either accept or deny a challenge. If accepted, it will generate a random riddle and if the answer is incorrect, **-5HP** is subtracted from the player. If they answer correctly, they are awarded with a **Staff of Protection**. 

### Monsters

There are currently the following monster types:
- Zombie - The zombie has slightly more attack, and because it is dead, has an almost definite chance of choosing to attack rather than defend.
- Vampire - The vampire deals moderate damage, and the chance of attacking or defending is more balanced than others (65% defend, 35% attack)
- Goblin - The Goblin has more health, but lower damage, and therefore is more likely to defend than attack.

*Created with JetBrains CLion.*
