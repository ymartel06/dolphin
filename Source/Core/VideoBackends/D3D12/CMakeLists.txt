add_library(videod3d
  main.cpp
  VideoBackend.h
)

target_link_libraries(videod3d
PUBLIC
  common
  videocommon
)
