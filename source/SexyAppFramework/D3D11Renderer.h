#ifndef __D3D11RENDERER_H__
#define __D3D11RENDERER_H__

#include "RendererInterface.h"

class D3D11Renderer : public RendererInterface {
public:
    void					Cleanup() override {};
    bool                    PreDraw() override { return true; };
    void                    Flush() override {};
    void                    PushTransform(const SexyMatrix3& theTransform, bool concatenate = true) override {}
    void                    PopTransform() override {};

    bool                    CreateImageTexture(MemoryImage* theImage) override { return true; }
    bool                    RecoverBits(MemoryImage* theImage) override { return true; };
    void                    SetCurTexture(MemoryImage* theImage) override {};
    void					RemoveMemoryImage(MemoryImage* theImage) override {};

    void                    Blt(Image* theImage, float theX, float theY, const Rect& theSrcRect, const Color& theColor, int theDrawMode, bool linearFilter = false) override {};
    void                    BltClipF(Image* theImage, float theX, float theY, const Rect& theSrcRect, const Rect* theClipRect, const Color& theColor, int theDrawMode) override {};
    void                    BltMirror(Image* theImage, float theX, float theY, const Rect& theSrcRect, const Color& theColor, int theDrawMode, bool linearFilter = false) override {};
    void                    StretchBlt(Image* theImage, const Rect& theDestRect, const Rect& theSrcRect, const Rect* theClipRect, const Color& theColor, int theDrawMode, bool fastStretch, bool mirror = false) override {};
    void                    BltRotated(Image* theImage, float theX, float theY, const Rect* theClipRect, const Color& theColor, int theDrawMode, double theRot, float theRotCenterX, float theRotCenterY, const Rect& theSrcRect) override {};
    void                    BltTransformed(Image* theImage, const Rect* theClipRect, const Color& theColor, int theDrawMode, const Rect& theSrcRect, const SexyMatrix3& theTransform, bool linearFilter, float theX , float theY , bool center = false) override {};

    void                    DrawLine(double theStartX, double theStartY, double theEndX, double theEndY, const Color& theColor, int theDrawMode) override {};
    void                    FillRect(const Rect& theRect, const Color& theColor, int theDrawMode) override {};
    void                    DrawTriangle(const TriVertex& p1, const TriVertex& p2, const TriVertex& p3, const Color& theColor, int theDrawMode) override {};
    void					DrawTriangleTex(const TriVertex& p1, const TriVertex& p2, const TriVertex& p3, const Color& theColor, int theDrawMode, Image* theTexture, bool blend = true) override {};
    void					DrawTrianglesTex(const TriVertex theVertices[][3], int theNumTriangles, const Color& theColor, int theDrawMode, Image* theTexture, float tx , float ty , bool blend = true) override {};
    void					DrawTrianglesTexStrip(const TriVertex theVertices[], int theNumTriangles, const Color& theColor, int theDrawMode, Image* theTexture, float tx , float ty , bool blend = true) override {};
    void					FillPoly(const Point theVertices[], int theNumVertices, const Rect* theClipRect, const Color& theColor, int theDrawMode, int tx, int ty) override {};
};
#endif //__D3D11RENDERER_H__