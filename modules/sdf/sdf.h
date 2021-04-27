
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

#include "core/arithmetics.hpp"
#include "core/Vector2.h"
#include "core/Projection.h"
#include "core/Scanline.h"
#include "core/Shape.h"
#include "core/BitmapRef.hpp"
#include "core/Bitmap.h"
#include "core/bitmap-interpolation.hpp"
#include "core/pixel-conversion.hpp"
#include "core/edge-coloring.h"
#include "core/generator-config.h"
#include "core/rasterization.h"
#include "core/sdf-error-estimation.h"

#define MSDFGEN_VERSION "1.8"

namespace msdfgen {

/// Generates a conventional single-channel signed distance field.
void generateSDF(const BitmapRef<float, 1> &output, const Shape &shape, const Projection &projection, double range, const GeneratorConfig &config = GeneratorConfig());

// Old version of the function API's kept for backwards compatibility
void generateSDF(const BitmapRef<float, 1> &output, const Shape &shape, double range, const Vector2 &scale, const Vector2 &translate, bool overlapSupport = true);

}
