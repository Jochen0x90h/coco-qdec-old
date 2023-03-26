#include "QuadratureDecoder_Dummy.hpp"


namespace coco {

QuadratureDecoder_Dummy::QuadratureDecoder_Dummy() {
}

Awaitable<QuadratureDecoder::Parameters> QuadratureDecoder_Dummy::change(int& delta) {
	delta = 0;
	return {};
}

} // namespace coco
