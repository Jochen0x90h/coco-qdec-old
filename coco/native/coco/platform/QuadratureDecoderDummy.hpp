#pragma once

#include <coco/QuadratureDecoder.hpp>


/**
 * Dummy implementation
*/
namespace coco {

class QuadratureDecoderDummy : public QuadratureDecoder {
public:

	QuadratureDecoderDummy();

	Awaitable<Parameters> change(int& delta) override;

protected:

};

} // namespace coco
