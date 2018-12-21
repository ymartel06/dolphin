// Copyright 2011 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <string>
#include "VideoCommon/VideoBackendBase.h"

namespace DX12
{
class VideoBackend : public VideoBackendBase
{
  bool Initialize(const WindowSystemInfo& wsi) override;
  void Shutdown() override;

  std::string GetName() const override;
  std::string GetDisplayName() const override;

  void InitBackendInfo() override;
};
}  // namespace DX11
