#ifndef __RENDERER_I__
#define __RENDERER_I__

#include "Common.h"
#include "MemoryImage.h"
#include "SexyMatrix.h"

class IRenderer {
public:
    virtual ~IRenderer() = default;

    virtual bool  PreDraw() = 0;
    virtual void  Flush() = 0;
    virtual void  PushTransform(const Sexy::SexyMatrix3& t, bool concat = true) = 0;
    virtual void  PopTransform() = 0;

    virtual bool  CreateImageTexture(Sexy::MemoryImage* img) = 0;
    virtual bool  RecoverBits(Sexy::MemoryImage* img) = 0;
    virtual void  SetCurTexture(Sexy::MemoryImage* img) = 0;

    virtual void  Blt(Sexy::Image* img, float x, float y, const Sexy::Rect& src, const Sexy::Color& c,
        int drawMode, bool linearFilter = false) = 0;
    virtual void  BltClipF(Sexy::Image* img, float x, float y, const Sexy::Rect& src,
        const Sexy::Rect* clip, const Sexy::Color& c, int drawMode) = 0;
    virtual void  BltMirror(Sexy::Image* img, float x, float y, const Sexy::Rect& src,
        const Sexy::Color& c, int drawMode, bool linear = false) = 0;
    virtual void  StretchBlt(Sexy::Image* img, const Sexy::Rect& dst, const Sexy::Rect& src,
        const Sexy::Rect* clip, const Sexy::Color& c, int drawMode,
        bool fastStretch, bool mirror = false) = 0;
    virtual void  BltRotated(Sexy::Image* img, float x, float y, const Sexy::Rect* clip,
        const Sexy::Color& c, int drawMode, double rot,
        float cx, float cy, const Sexy::Rect& src) = 0;
    virtual void  BltTransformed(Sexy::Image* img, const Sexy::Rect* clip, const Sexy::Color& c,
        int drawMode, const Sexy::Rect& src,
        const Sexy::SexyMatrix3& xf, bool linear,
        float x = 0, float y = 0, bool center = false) = 0;

    virtual void  DrawLine(double x1, double y1, double x2, double y2,
        const Sexy::Color& c, int drawMode) = 0;
    virtual void  FillRect(const Sexy::Rect& r, const Sexy::Color& c, int drawMode) = 0;
};

#endif