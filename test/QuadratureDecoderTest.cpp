#include <coco/loop.hpp>
#include <coco/debug.hpp>
#include <coco/board/QuadratureDecoder.hpp>


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
	loop::init();
	debug::init();
	board::QuadratureDecoder decoder;

	handleDecoder(decoder);

	loop::run();
}
