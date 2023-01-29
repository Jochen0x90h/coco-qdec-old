#pragma once

#include <coco/platform/Loop_native.hpp>
#include <coco/platform/QuadratureDecoder_Dummy.hpp>


using namespace coco;

// drivers for QuadratureDecoderTest
struct Drivers {
	Loop_native loop;
	QuadratureDecoder_Dummy quadratureDecoder;
};
