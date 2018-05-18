cmake_minimum_required(VERSION 3.9)
project(coursework)

set(CMAKE_CXX_STANDARD 11)

add_executable(coursework
        buddy.cpp
        buddy.d
        buddy.o
        sched-rr.cpp
        sched-rr.d
        sched-rr.o
        tarfs.cpp
        tarfs.d
        tarfs.h
        tarfs.o)
