add_library(Particle Particle.cxx)
target_include_directories(Particle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(VectorLibrary STATIC v2.cxx)
target_link_libraries(Particle PUBLIC VectorLibrary)
target_include_directories(VectorLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_library(RandomLibrary STATIC randomize.cxx)
target_link_libraries(Particle PUBLIC RandomLibrary)
target_include_directories(RandomLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})