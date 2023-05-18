#pragma once

#include <coco/QuadratureDecoder.hpp>


/**
	Dummy implementation
*/
namespace coco {

class QuadratureDecoder_Dummy : public QuadratureDecoder {
public:

	QuadratureDecoder_Dummy();

	Awaitable<Parameters> change(int& delta) override;

protected:

};

} // namespace coco
