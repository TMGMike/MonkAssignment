cmake_minimum_required(VERSION 3.12)
project(MonkAssignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(MonkAssignment main.cpp Room.cpp Room.h Controllers/MonsterController.cpp Controllers/MonsterController.h Models/MonsterModel.h Models/PlayerModel.cpp Models/PlayerModel.h Controllers/DungeonController.cpp Controllers/DungeonController.h main.h Controllers/LogController.cpp Controllers/LogController.h MonsterRoom.cpp MonsterRoom.h EmptyRoom.cpp EmptyRoom.h Controllers/PlayerController.cpp Controllers/PlayerController.h TreasureRoom.cpp TreasureRoom.h Controllers/RandomController.cpp Controllers/RandomController.h)