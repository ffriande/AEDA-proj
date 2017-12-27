cmake_minimum_required(VERSION 3.9)
project(AEDA)

set(CMAKE_CXX_STANDARD 11)

add_executable(AEDA
        BST.h
        casualclients.txt
        cflights.txt
        Company.cpp
        Company.h
        comreservations.txt
        Date.cpp
        Date.h
        main.cpp
        Operator.cpp
        Operator.h
        Passenger.cpp
        Passenger.h
        Plane.cpp
        Plane.h
        planes.txt
        premiumclients.txt
        Reservation.cpp
        Reservation.h
        Voo.cpp
        Voo.h)
