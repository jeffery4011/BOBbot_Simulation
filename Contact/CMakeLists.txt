add_library(BOBbot BOBbot.cxx)

add_library(ContactLibrary STATIC contact.cxx)
target_link_libraries(BOBbot PRIVATE ContactLibrary)