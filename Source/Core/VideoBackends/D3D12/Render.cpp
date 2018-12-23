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

void Renderer::CreateRtvAndDsvDescriptorHeaps()
{
  /*
  D3D12_COMMAND_QUEUE_DESC queueDesc = {};
  queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
  queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
  ThrowIfFailed(md3dDevice->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&mCommandQueue)));

  ThrowIfFailed(md3dDevice->CreateCommandAllocator(
      D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(mDirectCmdListAlloc.GetAddressOf())));

  ThrowIfFailed(
      md3dDevice->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT,
                                    mDirectCmdListAlloc.Get(),  // Associated command allocator
                                    nullptr,                    // Initial PipelineStateObject
                                    IID_PPV_ARGS(mCommandList.GetAddressOf())));

  // Start off in a closed state.  This is because the first time we refer
  // to the command list we will Reset it, and it needs to be closed before
  // calling Reset.
  mCommandList->Close();
  */
}

void Renderer::CreateCommandObjects()
{
}

void Renderer::CreateSwapChain()
{
}

bool Renderer::InitDirect3D()
{
  return false;
}

}  // namespace DX12
