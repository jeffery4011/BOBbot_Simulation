cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(BOBbot_simulation VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_subdirectory(Particle)
add_subdirectory(Contact)
add_subdirectory(Interaction_Force)
add_subdirectory(Solver)
add_subdirectory(Ring)

# TODO 2: Use add_subdirectory() to add MathFunctions to this project

# add the executable
add_executable(BOBbot_simulation BOBbot_simulation.cxx)
target_link_libraries(BOBbot_simulation PUBLIC Particle)
target_link_libraries(BOBbot_simulation glfw)
target_link_libraries(BOBbot_simulation PUBLIC ContactLibrary)
target_link_libraries(BOBbot_simulation PUBLIC Interaction_Force_Library)
target_link_libraries(BOBbot_simulation PUBLIC Solver)
target_link_libraries(BOBbot_simulation PUBLIC Ring)
# TODO 3: Use target_link_libraries to link the library to our executable

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(BOBbot_simulation PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/Particle"
                           "${PROJECT_SOURCE_DIR}/Contact"
                           "${PROJECT_SOURCE_DIR}/Interaction_Force"
                           "${PROJECT_SOURCE_DIR}/Solver"
                           "${PROJECT_SOURCE_DIR}/Ring"
                           )

              