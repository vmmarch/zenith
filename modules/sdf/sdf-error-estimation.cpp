
#include "sdf-error-estimation.h"

#include <cmath>
#include "arithmetics.hpp"

namespace msdfgen {

void scanlineSDF(Scanline &line, const BitmapConstRef<float, 1> &sdf, const Projection &projection, double y, bool inverseYAxis) {
    if (!(sdf.width > 0 && sdf.height > 0))
        return line.setIntersections(std::vector<Scanline::Intersection>());
    double pixelY = clamp(projection.projectY(y)-.5, double(sdf.height-1));
    if (inverseYAxis)
        pixelY = sdf.height-1-pixelY;
    int b = (int) floor(pixelY);
    int t = b+1;
    double bt = pixelY-b;
    if (t >= sdf.height) {
        b = sdf.height-1;
        t = sdf.height-1;
        bt = 1;
    }
    bool inside = false;
    std::vector<Scanline::Intersection> intersections;
    float lv, rv = mix(*sdf(0, b), *sdf(0, t), bt);
    if ((inside = rv > .5f)) {
        Scanline::Intersection intersection = { -1e240, 1 };
        intersections.push_back(intersection);
    }
    for (int l = 0, r = 1; r < sdf.width; ++l, ++r) {
        lv = rv;
        rv = mix(*sdf(r, b), *sdf(r, t), bt);
        if (lv != rv) {
            double lr = double(.5f-lv)/double(rv-lv);
            if (lr >= 0 && lr <= 1) {
                Scanline::Intersection intersection = { projection.unprojectX(l+lr+.5), sign(rv-lv) };
                intersections.push_back(intersection);
            }
        }
    }
#ifdef MSDFGEN_USE_CPP11
    line.setIntersections((std::vector<Scanline::Intersection> &&) intersections);
#else
    line.setIntersections(intersections);
#endif
}

template <int N>
double estimateSDFErrorInner(const BitmapConstRef<float, N> &sdf, const Shape &shape, const Projection &projection, int scanlinesPerRow, FillRule fillRule) {
    if (sdf.width <= 1 || sdf.height <= 1 || scanlinesPerRow < 1)
        return 0;
    double subRowSize = 1./scanlinesPerRow;
    double xFrom = projection.unprojectX(.5);
    double xTo = projection.unprojectX(sdf.width-.5);
    double overlapFactor = 1/(xTo-xFrom);
    double error = 0;
    Scanline refScanline, sdfScanline;
    for (int row = 0; row < sdf.height-1; ++row) {
        for (int subRow = 0; subRow < scanlinesPerRow; ++subRow) {
            double bt = (subRow+.5)*subRowSize;
            double y = projection.unprojectY(row+bt+.5);
            shape.scanline(refScanline, y);
            scanlineSDF(sdfScanline, sdf, projection, y, shape.inverseYAxis);
            error += 1-overlapFactor*Scanline::overlap(refScanline, sdfScanline, xFrom, xTo, fillRule);
        }
    }
    return error/((sdf.height-1)*scanlinesPerRow);
}

double estimateSDFError(const BitmapConstRef<float, 1> &sdf, const Shape &shape, const Projection &projection, int scanlinesPerRow, FillRule fillRule) {
    return estimateSDFErrorInner(sdf, shape, projection, scanlinesPerRow, fillRule);
}

// Legacy API

void scanlineSDF(Scanline &line, const BitmapConstRef<float, 1> &sdf, const Vector2 &scale, const Vector2 &translate, bool inverseYAxis, double y) {
    scanlineSDF(line, sdf, Projection(scale, translate), y, inverseYAxis);
}

double estimateSDFError(const BitmapConstRef<float, 1> &sdf, const Shape &shape, const Vector2 &scale, const Vector2 &translate, int scanlinesPerRow, FillRule fillRule) {
    return estimateSDFError(sdf, shape, Projection(scale, translate), scanlinesPerRow, fillRule);
}
}
