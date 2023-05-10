add_library(weapons
  none.cpp
  hammer.cpp
  knife.cpp
  mace.cpp
  staff.cpp
  )

target_include_directories(weapons PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(weapons PUBLIC engine events)
