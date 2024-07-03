cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(BOBbot_simulation VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")


add_subdirectory(BOBbot)
add_subdirectory(Contact)


# TODO 2: Use add_subdirectory() to add MathFunctions to this project

# add the executable
add_executable(BOBbot_simulation BOBbot_simulation.cxx)
target_link_libraries(BOBbot_simulation "${TORCH_LIBRARIES}")
target_link_libraries(BOBbot_simulation PUBLIC BOBbot)
target_link_libraries(BOBbot_simulation PUBLIC ContactLibrary)
# TODO 3: Use target_link_libraries to link the library to our executable

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(BOBbot_simulation PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/BOBbot"
                           "${PROJECT_SOURCE_DIR}/Contact"
                           )

                           
if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET example-app
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:example-app>)
endif (MSVC)