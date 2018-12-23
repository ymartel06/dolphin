// Copyright 2010 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

// Windows Runtime Library. Needed for Microsoft::WRL::ComPtr<> template class.
#include <wrl.h>
using namespace Microsoft::WRL;

#include <d3d12.h>
#include <dxgi1_6.h>
#include "VideoCommon/RenderBase.h"

namespace DX12
{

class Renderer : public ::Renderer
{
public:
  Renderer(int backbuffer_width, int backbuffer_height);
  ~Renderer() override;

private:
  void CreateRtvAndDsvDescriptorHeaps();
  void CreateCommandObjects();
  void CreateSwapChain();
  bool InitDirect3D();

  ComPtr<IDXGIFactory4> m_dxgi_factory;
  /*
  Microsoft::WRL::ComPtr<IDXGISwapChain> m_swap_chain;
  Microsoft::WRL::ComPtr<ID3D12Device> m_d3d_device;

  Microsoft::WRL::ComPtr<ID3D12Fence> m_fence;
  UINT64 m_current_fence = 0;

  Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_command_queue;
  Microsoft::WRL::ComPtr<ID3D12CommandAllocator> m_direct_cmd_list_alloc;
  Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> m_command_list;

  static const int SwapChainBufferCount = 2;
  int m_current_back_buffer = 0;
  Microsoft::WRL::ComPtr<ID3D12Resource> m_swap_chain_buffer[SwapChainBufferCount];
  Microsoft::WRL::ComPtr<ID3D12Resource> m_depth_stencil_buffer;

  Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_rtv_heap;
  Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_dsv_heap;
  */
};
}  // namespace DX12
