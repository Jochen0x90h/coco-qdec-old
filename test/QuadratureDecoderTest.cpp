#include <coco/loop.hpp>
#include <coco/debug.hpp>
#include <coco/board/QuadratureDecoderTest.hpp>


using namespace coco;

Coroutine handleDecoder(QuadratureDecoder &decoder) {
	while (true) {
		int delta;

		// wait until quadrature decoder reports a movement
		co_await decoder.change(delta);

		debug::set(delta);
	}
}

int main() {
	debug::init();
	board::QuadratureDecoderTest drivers;

	handleDecoder(drivers.quadratureDecoder);

	loop::run();
}
