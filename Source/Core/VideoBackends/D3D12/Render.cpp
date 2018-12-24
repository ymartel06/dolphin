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
  // Release the previous swapchain we will be recreating.
  m_swap_chain.Reset();

  DXGI_SWAP_CHAIN_DESC sd;
  sd.BufferDesc.Width = m_backbuffer_width;
  sd.BufferDesc.Height = m_backbuffer_height;
  sd.BufferDesc.RefreshRate.Numerator = 60;
  sd.BufferDesc.RefreshRate.Denominator = 1;
  sd.BufferDesc.Format = m_back_buffer_format;
  sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
  sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
  sd.SampleDesc.Count = 1; // TODO: init MSAA here
  sd.SampleDesc.Quality = 0; // TODO: init MSAA here
  sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
  sd.BufferCount = SwapChainBufferCount;
  // if (FAILED(D3D::Create(reinterpret_cast<HWND>(wsi.render_surface))))
  sd.OutputWindow = mhMainWnd; 
  sd.Windowed = true;
  sd.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
  sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

  // Note: Swap chain uses queue to perform flush.
  ThrowIfFailed(m_dxgi_factory->CreateSwapChain(m_command_queue.Get(), &sd, m_swap_chain.GetAddressOf()));
}

bool Renderer::InitDirect3D()
{
  return false;
}

}  // namespace DX12
