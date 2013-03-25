project(chapter3)
cmake_minimum_required(VERSION 2.6)

include_directories(/home/jeff/gmock-1.6.0/include /home/jeff/gmock-1.6.0/gtest/include)
link_directories(/home/jeff/gmock-1.6.0/mybuild /home/jeff/gmock-1.6.0/gtest/mybuild)
add_definitions(-std=c++0x)

set(sources 
   main.cpp 
   ParameterizedTest.cpp
   RetweetCollectionTest.cpp 
   RetweetCollection.cpp
   TweetTest.cpp
   Tweet.cpp)
add_executable(test ${sources})
target_link_libraries(test pthread)
target_link_libraries(test gmock)
target_link_libraries(test gtest)

