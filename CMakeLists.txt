cmake_minimum_required(VERSION 3.22)
project(Brain C)

set(CMAKE_C_STANDARD 99)

add_executable(Brain main.c
        Neuron.c
        Neuron.h
        list.c
        list.h
        cluster.c
        cluster.h
        network.c
        network.h)