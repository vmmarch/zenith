
#pragma once

/*
 * MULTI-CHANNEL SIGNED DISTANCE FIELD GENERATOR v1.8 (2020-10-17)
 * ---------------------------------------------------------------
 * A utility by Viktor Chlumsky, (c) 2014 - 2020
 *
 * The technique used to generate multi-channel distance fields in this code
 * has been developed by Viktor Chlumsky in 2014 for his master's thesis,
 * "Shape Decomposition for Multi-Channel Distance Fields". It provides improved
 * quality of sharp corners in glyphs and other 2D shapes compared to monochrome
 * distance fields. To reconstruct an image of the shape, apply the median of three
 * operation on the triplet of sampled signed distance values.
 *
 */

#include "arithmetics.hpp"
#include "Vector2.h"
#include "Projection.h"
#include "Scanline.h"
#include "Shape.h"
#include "BitmapRef.hpp"
#include "Bitmap.h"
#include "bitmap-interpolation.hpp"
#include "pixel-conversion.hpp"
#include "edge-coloring.h"
#include "generator-config.h"
#include "rasterization.h"
#include "sdf-error-estimation.h"

#define MSDFGEN_VERSION "1.8"

#ifndef SDF_API 
    #define SDF_API extern "C" __declspec(dllexport)
#endif

struct SDFImage {
    int width;
    int height;
    void* pixels;
};
SDF_API void* sdfCreateShape();
SDF_API void* sdfAddContour(void* shape);
SDF_API void sdfAddLine(void* contour, double startX, double startY, double endX, double endY);
SDF_API void sdfAddCurve(void* contour, double startX, double startY, double endX, double endY, double controlX, double controlY);
SDF_API void* sdfGenerate(void* shape, double x, double y, double width, double height, double scaleWidth, double scaleHeight, double range); // 返回一个STBImage并删除shape
SDF_API int sdfImageWidth(void* image);
SDF_API int sdfImageHeight(void* image);
SDF_API void* sdfImagePixels(void* image);
SDF_API void sdfFreeImage(void* image);

namespace msdfgen {

/// Generates a conventional single-channel signed distance field.
void generateSDF(const BitmapRef<float, 1> &output, const Shape &shape, const Projection &projection, double range, const GeneratorConfig &config = GeneratorConfig());

// Old version of the function API's kept for backwards compatibility
void generateSDF(const BitmapRef<float, 1> &output, const Shape &shape, double range, const Vector2 &scale, const Vector2 &translate, bool overlapSupport = true);

}
