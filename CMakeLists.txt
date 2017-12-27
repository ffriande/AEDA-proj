cmake_minimum_required(VERSION 3.9)
project(AEDA_proj_master)

set(CMAKE_CXX_STANDARD 11)

add_executable(AEDA_proj_master
        BST.h
        Company.cpp
        Company.h
        Date.cpp
        Date.h
        main.cpp
        Passenger.cpp
        Passenger.h
        Plane.cpp
        Plane.h
        Reservation.cpp
        Reservation.h
        Voo.cpp
        Voo.h Operator.cpp Operator.h)
