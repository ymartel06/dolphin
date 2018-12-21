// Copyright 2008 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#include <memory>
#include <string>

#include "Common/Common.h"
#include "Common/CommonTypes.h"
#include "Common/MsgHandler.h"
#include "Common/StringUtil.h"

#include "VideoBackends/D3D12/VideoBackend.h"

#include "VideoCommon/ShaderCache.h"
#include "VideoCommon/VideoCommon.h"
#include "VideoCommon/VideoConfig.h"

namespace DX12
{
std::string VideoBackend::GetName() const
{
  return "D3D12";
}

std::string VideoBackend::GetDisplayName() const
{
  return _trans("Direct3D 12");
}

void VideoBackend::InitBackendInfo()
{

}

bool VideoBackend::Initialize(const WindowSystemInfo& wsi)
{
  return false;
}

void VideoBackend::Shutdown()
{

}
}  // namespace DX12
