#pragma once

#include <coco/platform/RotaryKnob_emu.hpp>


using namespace coco;

// drivers for QuadratureDecoderTest
struct Drivers {
	Loop_emu loop;
	RotaryKnob_emu quadratureDecoder{loop, 100};
};
