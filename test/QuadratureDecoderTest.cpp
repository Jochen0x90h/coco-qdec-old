#include <coco/loop.hpp>
#include <coco/debug.hpp>
#include <QuadratureDecoderTest.hpp>


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
	Drivers drivers;

	handleDecoder(drivers.quadratureDecoder);

	drivers.loop.run();
}
