#include "RendererFactory.h"
#include "D3DInterface.h"            
std::unique_ptr<RendererInterface> CreateD3D11Renderer(); 

std::unique_ptr<RendererInterface> CreateRenderer(bool useD3D11) {
    if (useD3D11) return CreateD3D11Renderer();
    return std::make_unique<Sexy::D3DInterface>();
}