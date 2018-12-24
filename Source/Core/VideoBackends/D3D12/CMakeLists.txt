add_library(videod3d
  D3DUtil.h
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
