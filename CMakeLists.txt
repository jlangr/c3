project(chapter3)
cmake_minimum_required(VERSION 2.6)

include_directories(/home/jlangr/gmock-1.6.0/include /home/jlangr/gmock-1.6.0/gtest/include)
link_directories(/home/jlangr/gmock-1.6.0/mybuild /home/jlangr/gmock-1.6.0/gtest/mybuild)
add_definitions(-std=c++0x)

set(sources 
   main.cpp 
   RetweetCollectionTest.cpp 
   RetweetCollection.cpp
   Tweet.cpp)
add_executable(test ${sources})
target_link_libraries(test pthread)
target_link_libraries(test gmock)
target_link_libraries(test gtest)
target_link_libraries(test rt)

# add_custom_command(TARGET run DEPENDS ./test
#    COMMAND ./test
# )

