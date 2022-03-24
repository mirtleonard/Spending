cmake_minimum_required(VERSION 3.21)
project(lab3 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab3 main.c domain/spending.c domain/spending.h repository/repository.c repository/repository.h utils/service.c utils/service.h ui/ui.c ui/ui.h validators/validator.c validators/validator.h)
