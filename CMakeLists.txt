cmake_minimum_required(VERSION 3.12)
project(MonkAssignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(MonkAssignment main.cpp Controllers/RoomController.cpp Controllers/RoomController.h Room.cpp Room.h Controllers/MonsterController.cpp Controllers/MonsterController.h Models/MonsterModel.h Models/PlayerModel.cpp Models/PlayerModel.h Controllers/DungeonController.cpp Controllers/DungeonController.h main.h Controllers/LogController.cpp Controllers/LogController.h Models/RoomModel.cpp Models/RoomModel.h MonsterRoom.cpp MonsterRoom.h)