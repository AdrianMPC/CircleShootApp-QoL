#include "D3D11Renderer.h"
#include <memory>

std::unique_ptr<RendererInterface> CreateD3D11Renderer() {
	return std::make_unique<D3D11Renderer>();
}