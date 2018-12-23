// Copyright 2010 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include "VideoCommon/RenderBase.h"

namespace DX12
{

class Renderer : public ::Renderer
{
public:
  Renderer(int backbuffer_width, int backbuffer_height);
  ~Renderer() override;
};
}  // namespace DX12
