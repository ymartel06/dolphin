add_library(videod3d
  main.cpp
  Render.cpp
  Render.h
  VideoBackend.h
)

target_link_libraries(videod3d
PUBLIC
  common
  videocommon
)
