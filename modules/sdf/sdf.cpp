
/*
 * MULTI-CHANNEL SIGNED DISTANCE FIELD GENERATOR v1.8 (2020-10-17) - standalone console program
 * --------------------------------------------------------------------------------------------
 * A utility by Viktor Chlumsky, (c) 2014 - 2020
 *
 */

#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>

#include "sdf.h"

#include "ShapeDistanceFinder.h"

using namespace msdfgen;

template <int N>
static void invertColor(const BitmapRef<float, N> &bitmap) {
    const float *end = bitmap.pixels+N*bitmap.width*bitmap.height;
    for (float *p = bitmap.pixels; p < end; ++p)
        *p = 1.f-*p;
}

SDF_API void* sdfCreateShape() {
    return new Shape();
}
SDF_API void* sdfAddContour(void* shape) {
    return &((Shape*)shape)->addContour();
}
SDF_API void sdfAddLine(void* contour, double startX, double startY, double endX, double endY) {
    ((Contour*)contour)->edges.push_back(new LinearSegment(Point2(startX, startY), Point2(endX, endY)));
}
SDF_API void sdfAddCurve(void* contour, double startX, double startY, double endX,
 double endY, double controlX, double controlY) {
     ((Contour*)contour)->edges.push_back(new QuadraticSegment(Point2(startX, startY), Point2(endX, endY), Point2(controlX, controlY)));
 }
SDF_API void* sdfGenerate(void* shape, double x, double y, double width, double height, double scaleWidth, double scaleHeight, double range) {
    if(!((Shape*)shape)->validate()) {
        return NULL;
    }
    ((Shape*)shape)->normalize();
    Bitmap<float, 1> sdf = Bitmap<float, 1>(width, height);
    generateSDF(sdf, *((Shape*)shape), range, Point2(scaleWidth, scaleHeight), Point2(x, y), true);
	invertColor<1>(sdf);
    
    SDFImage *image = (SDFImage*)malloc(sizeof(SDFImage));
    image->width = sdf.width();
    image->height = sdf.height();
    image->pixels = malloc(image->width*image->height);
    for(int i = 0; i<image->width; i++) {
        for(int j = 0; j<image->height; j++) {
            ((byte*)image->pixels)[i*image->height+j] = pixelFloatToByte(*sdf(i, j));
        }
    }
    if(shape != NULL) {
        Shape* s = (Shape*)shape;
        delete s;
    }

    return image;
}

SDF_API int sdfImageWidth(void* image) {
    return((SDFImage*)image)->width;
}
SDF_API int sdfImageHeight(void* image) {
    return((SDFImage*)image)->height;
}
SDF_API void* sdfImagePixels(void* image) {
    return((SDFImage*)image)->pixels;
}
SDF_API void sdfFreeImage(void* image) {
    free(((SDFImage*)image)->pixels);
    ((SDFImage*)image)->pixels = NULL;
}