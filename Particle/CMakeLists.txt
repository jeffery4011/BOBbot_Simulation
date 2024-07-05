add_library(BOBbot BOBbot.cxx)
target_include_directories(BOBbot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(VectorLibrary STATIC v2.cxx)
target_link_libraries(BOBbot PUBLIC VectorLibrary)
target_include_directories(VectorLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_library(RandomLibrary STATIC randomize.cxx)
target_link_libraries(BOBbot PUBLIC RandomLibrary)
target_include_directories(RandomLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})