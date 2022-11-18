cmake_minimum_required(VERSION 3.22)
project(ProjectChaonia)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectChaonia main.cpp Object.cpp Object.h World.cpp World.h Room.cpp Room.h GlobalConstants.h Connection.cpp Connection.h FlaggedConnection.cpp FlaggedConnection.h Flag.cpp Flag.h Player.cpp Player.h)
