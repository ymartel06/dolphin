#include "VideoBackends/D3D12/Render.h"
#include "VideoBackends/D3D12/D3DUtil.h"

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
  D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc;
  rtvHeapDesc.NumDescriptors = SwapChainBufferCount;
  rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
  rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
  rtvHeapDesc.NodeMask = 0;
  ThrowIfFailed(
      m_d3d_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(m_rtv_heap.GetAddressOf())));

  D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc;
  dsvHeapDesc.NumDescriptors = 1;
  dsvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
  dsvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
  dsvHeapDesc.NodeMask = 0;
  ThrowIfFailed(
      m_d3d_device->CreateDescriptorHeap(&dsvHeapDesc, IID_PPV_ARGS(m_dsv_heap.GetAddressOf())));
}

void Renderer::CreateCommandObjects()
{
  D3D12_COMMAND_QUEUE_DESC queueDesc = {};
  queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
  queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
  ThrowIfFailed(m_d3d_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_command_queue)));

  ThrowIfFailed(m_d3d_device->CreateCommandAllocator(
      D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(m_direct_cmd_list_alloc.GetAddressOf())));

  ThrowIfFailed(m_d3d_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT,
                                                m_direct_cmd_list_alloc.Get(),
                                                nullptr,  // Initial PipelineStateObject
                                                IID_PPV_ARGS(m_command_list.GetAddressOf())));

  // Start off in a closed state.  This is because the first time we refer
  // to the command list we will Reset it, and it needs to be closed before
  // calling Reset.
  m_command_list->Close();
}

void Renderer::CreateSwapChain()
{
}

bool Renderer::InitDirect3D()
{
  return false;
}

}  // namespace DX12
