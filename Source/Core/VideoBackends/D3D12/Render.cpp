#include "VideoBackends/D3D12/Render.h"

namespace DX12
{

Renderer::Renderer(int backbuffer_width, int backbuffer_height)
    : ::Renderer(backbuffer_width, backbuffer_height, AbstractTextureFormat::RGBA8)
{

}

Renderer::~Renderer()
{

}

}  // namespace DX12
