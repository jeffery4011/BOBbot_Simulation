add_library(BOBbot BOBbot.cxx)


add_library(VectorLibrary STATIC v2.cxx)
target_link_libraries(BOBbot PRIVATE VectorLibrary)


add_library(RandomLibrary STATIC randomize.cxx)
target_link_libraries(BOBbot PRIVATE RandomLibrary)