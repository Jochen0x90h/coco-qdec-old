#pragma once

#include <coco/QuadratureDecoder.hpp>
#include <coco/platform/Loop_RTC0.hpp>
#include <coco/platform/gpio.hpp>


/**
	Implementation of quadrature decoder for nRF52 using QDEC peripheral
	https://infocenter.nordicsemi.com/index.jsp?topic=%2Fps_nrf52840%2Fqdec.html&cp=5_0_0_5_17

	Dependencies:

	Resources:
		NRF_QDEC
*/
namespace coco {

class QuadratureDecoder_QDEC : public QuadratureDecoder, public Loop_RTC0::Handler {
public:
	/**
	 * Constructor
	 * @param aPin pin of input A of quadrature decoder
	 * @param bPin pin of input A of quadrature decoder
	 */
	QuadratureDecoder_QDEC(Loop_RTC0 &loop, int aPin, int bPin, gpio::Pull aPull = gpio::Pull::UP, gpio::Pull bPull = gpio::Pull::UP);

	Awaitable<Parameters> change(int& delta) override;

	void handle() override;

protected:

	int acc = 0;

	TaskList<Parameters> tasks;
};

} // namespace coco
