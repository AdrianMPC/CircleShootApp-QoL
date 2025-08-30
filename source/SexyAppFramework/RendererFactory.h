#ifndef __RENDERFACTORY_H__
#define __RENDERFACTORY_H__

#include <memory>
#include "RendererInterface.h"

std::unique_ptr<RendererInterface> CreateRenderer(bool useD3D11);

#endif // __RENDERFACTORY_H__
