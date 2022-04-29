cmake_minimum_required(VERSION 3.0.2)
project(voting)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)


# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )





catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES voting
  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)



add_executable(input src/input.cpp)
add_executable(counter src/counter.cpp)



 target_link_libraries(input
   ${catkin_LIBRARIES}
 )

target_link_libraries(counter
  ${catkin_LIBRARIES}
)




