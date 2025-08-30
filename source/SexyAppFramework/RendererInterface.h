#ifndef __RENDERERINTERFACE_H__
#define __RENDERERINTERFACE_H__

#include "Common.h"
#include "MemoryImage.h"
#include "SexyMatrix.h"

using namespace Sexy;

class RendererInterface {
public:
    virtual                         ~RendererInterface() = default;

    virtual void					Cleanup() = 0;
    virtual bool                    PreDraw() = 0;
    virtual void                    Flush() = 0;
    virtual void                    PushTransform(const SexyMatrix3& theTransform, bool concatenate = true) = 0;
    virtual void                    PopTransform() = 0;

    virtual bool                    CreateImageTexture(MemoryImage* theImage) = 0;
    virtual bool                    RecoverBits(MemoryImage* theImage) = 0;
    virtual void                    SetCurTexture(MemoryImage* theImage) = 0;
    virtual void					RemoveMemoryImage(MemoryImage* theImage) = 0;

    virtual void                    Blt(Image* theImage, float theX, float theY, const Rect& theSrcRect, const Color& theColor, int theDrawMode, bool linearFilter = false) = 0;
    virtual void                    BltClipF(Image* theImage, float theX, float theY, const Rect& theSrcRect, const Rect* theClipRect, const Color& theColor, int theDrawMode) = 0;
    virtual void                    BltMirror(Image* theImage, float theX, float theY, const Rect& theSrcRect, const Color& theColor, int theDrawMode, bool linearFilter = false) = 0;
    virtual void                    StretchBlt(Image* theImage, const Rect& theDestRect, const Rect& theSrcRect, const Rect* theClipRect, const Color& theColor, int theDrawMode, bool fastStretch, bool mirror = false) = 0;
    virtual void                    BltRotated(Image* theImage, float theX, float theY, const Rect* theClipRect, const Color& theColor, int theDrawMode, double theRot, float theRotCenterX, float theRotCenterY, const Rect& theSrcRect) = 0;
    virtual void                    BltTransformed(Image* theImage, const Rect* theClipRect, const Color& theColor, int theDrawMode, const Rect& theSrcRect, const SexyMatrix3& theTransform, bool linearFilter, float theX = 0, float theY = 0, bool center = false) = 0;

    virtual void                    DrawLine(double theStartX, double theStartY, double theEndX, double theEndY, const Color& theColor, int theDrawMode) = 0;
    virtual void                    FillRect(const Rect& theRect, const Color& theColor, int theDrawMode) = 0;
    virtual void                    DrawTriangle(const TriVertex& p1, const TriVertex& p2, const TriVertex& p3, const Color& theColor, int theDrawMode) = 0;
    virtual void					DrawTriangleTex(const TriVertex& p1, const TriVertex& p2, const TriVertex& p3, const Color& theColor, int theDrawMode, Image* theTexture, bool blend = true) = 0;
    virtual void					DrawTrianglesTex(const TriVertex theVertices[][3], int theNumTriangles, const Color& theColor, int theDrawMode, Image* theTexture, float tx = 0, float ty = 0, bool blend = true) = 0;
    virtual void					DrawTrianglesTexStrip(const TriVertex theVertices[], int theNumTriangles, const Color& theColor, int theDrawMode, Image* theTexture, float tx = 0, float ty = 0, bool blend = true) = 0;
    virtual void					FillPoly(const Point theVertices[], int theNumVertices, const Rect* theClipRect, const Color& theColor, int theDrawMode, int tx, int ty) = 0;
};
#endif