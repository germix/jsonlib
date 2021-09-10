cmake_minimum_required(VERSION 3.8)

project(jsonlib)

FILE(GLOB ALL_SOURCES src/*.cpp)

add_library(jsonlib STATIC ${ALL_SOURCES})

add_library(jsonlib_shared SHARED ${ALL_SOURCES})
