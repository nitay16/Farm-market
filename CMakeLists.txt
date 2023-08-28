cmake_minimum_required(VERSION 3.21)
project(Farm_market)

set(CMAKE_CXX_STANDARD 14)

add_executable(Farm_market Animal.h Animal.cpp Chicken.h Chicken.cpp ChickenFarm.h ChickenFarm.cpp Cow.h Cow.cpp CowFarm.h CowFarm.cpp Farm.h Farm.cpp farmMarket.cpp Market.h Market.cpp Sheep.h Sheep.cpp SheepFarm.h SheepFarm.cpp Farm_animal_Exceptions.h)
