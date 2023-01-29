#pragma once

#include <coco/platform/Loop_RTC0.hpp>
#include <coco/platform/QuadratureDecoder_QDEC.hpp>


using namespace coco;

// drivers for QuadratureDecoderTest
struct Drivers {
	Loop_RTC0 loop;
	QuadratureDecoder_QDEC quadratureDecoder{loop, gpio::P0(4), gpio::P0(5)};
};
