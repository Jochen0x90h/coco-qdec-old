#pragma once

#include <coco/QuadratureDecoder.hpp>
#include <coco/platform/handler.hpp>
#include <coco/platform/gpio.hpp>


/**
 * Implementation of quadrature decoder for nRF52 using QDEC peripheral
 * 
 * Dependencies:
 * 
 * Resources:
 *	NRF_QDEC
 */
namespace coco {

class QuadratureDecoder_QDEC : public QuadratureDecoder, public Handler {
public:
	/**
	 * Constructor
	 * @param aPin pin of input A of quadrature decoder
	 * @param bPin pin of input A of quadrature decoder
	 */
	QuadratureDecoder_QDEC(int aPin, int bPin, gpio::Pull aPull = gpio::Pull::UP, gpio::Pull bPull = gpio::Pull::UP);

	Awaitable<Parameters> change(int& delta) override;

	void handle() override;

protected:

	int acc = 0;

	Waitlist<Parameters> waitlist;
};

} // namespace coco
