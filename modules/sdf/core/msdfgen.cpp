
#include "sdf.h"

#include <vector>
#include "edge-selectors.h"
#include "contour-combiners.h"
#include "ShapeDistanceFinder.h"
#include "msdf-artifact-patcher.h"

namespace msdfgen {

template <typename DistanceType>
class DistancePixelConversion;

template <>
class DistancePixelConversion<double> {
public:
    typedef BitmapRef<float, 1> BitmapRefType;
    inline static void convert(float *pixels, double distance, double range) {
        *pixels = float(distance/range+.5);
    }
};

template <>
class DistancePixelConversion<MultiDistance> {
public:
    typedef BitmapRef<float, 3> BitmapRefType;
    inline static void convert(float *pixels, const MultiDistance &distance, double range) {
        pixels[0] = float(distance.r/range+.5);
        pixels[1] = float(distance.g/range+.5);
        pixels[2] = float(distance.b/range+.5);
    }
};

template <>
class DistancePixelConversion<MultiAndTrueDistance> {
public:
    typedef BitmapRef<float, 4> BitmapRefType;
    inline static void convert(float *pixels, const MultiAndTrueDistance &distance, double range) {
        pixels[0] = float(distance.r/range+.5);
        pixels[1] = float(distance.g/range+.5);
        pixels[2] = float(distance.b/range+.5);
        pixels[3] = float(distance.a/range+.5);
    }
};

template <class ContourCombiner>
void generateDistanceField(const typename DistancePixelConversion<typename ContourCombiner::DistanceType>::BitmapRefType &output, const Shape &shape, const Projection &projection, double range) {
#ifdef MSDFGEN_USE_OPENMP
    #pragma omp parallel
#endif
    {
        ShapeDistanceFinder<ContourCombiner> distanceFinder(shape);
        bool rightToLeft = false;
#ifdef MSDFGEN_USE_OPENMP
        #pragma omp for
#endif
        for (int y = 0; y < output.height; ++y) {
            int row = shape.inverseYAxis ? output.height-y-1 : y;
            for (int col = 0; col < output.width; ++col) {
                int x = rightToLeft ? output.width-col-1 : col;
                Point2 p = projection.unproject(Point2(x+.5, y+.5));
                typename ContourCombiner::DistanceType distance = distanceFinder.distance(p);
                DistancePixelConversion<typename ContourCombiner::DistanceType>::convert(output(x, row), distance, range);
            }
            rightToLeft = !rightToLeft;
        }
    }
}

void generateSDF(const BitmapRef<float, 1> &output, const Shape &shape, const Projection &projection, double range, const GeneratorConfig &config) {
    if (config.overlapSupport)
        generateDistanceField<OverlappingContourCombiner<TrueDistanceSelector> >(output, shape, projection, range);
    else
        generateDistanceField<SimpleContourCombiner<TrueDistanceSelector> >(output, shape, projection, range);
}

// Legacy API

void generateSDF(const BitmapRef<float, 1> &output, const Shape &shape, double range, const Vector2 &scale, const Vector2 &translate, bool overlapSupport) {
    generateSDF(output, shape, Projection(scale, translate), range, GeneratorConfig(overlapSupport));
}
}
