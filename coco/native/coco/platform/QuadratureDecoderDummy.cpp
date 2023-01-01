#include "QuadratureDecoderDummy.hpp"


namespace coco {

QuadratureDecoderDummy::QuadratureDecoderDummy() {
}

Awaitable<QuadratureDecoder::Parameters> QuadratureDecoderDummy::change(int& delta) {
	return {};
}

} // namespace coco
