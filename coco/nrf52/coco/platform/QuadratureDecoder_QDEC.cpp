#include "QuadratureDecoder_QDEC.hpp"


namespace coco {

QuadratureDecoder_QDEC::QuadratureDecoder_QDEC(Loop_RTC0 &loop, int aPin, int bPin, gpio::Pull aPull, gpio::Pull bPull) {
	configureInput(aPin, aPull);
	configureInput(bPin, bPull);

	// configure quadrature decoder
	NRF_QDEC->SHORTS = N(QDEC_SHORTS_REPORTRDY_RDCLRACC, Enabled); // clear accumulator register on report
	NRF_QDEC->INTENSET = N(QDEC_INTENSET_REPORTRDY, Set);
	NRF_QDEC->SAMPLEPER = N(QDEC_SAMPLEPER_SAMPLEPER, 1024us);
	NRF_QDEC->REPORTPER = N(QDEC_REPORTPER_REPORTPER, 10Smpl);
	NRF_QDEC->PSEL.A = aPin;
	NRF_QDEC->PSEL.B = bPin;
	NRF_QDEC->DBFEN = N(QDEC_DBFEN_DBFEN, Enabled); // enable debounce filter
	NRF_QDEC->ENABLE = N(QDEC_ENABLE_ENABLE, Enabled);
	NRF_QDEC->TASKS_START = TRIGGER;

	// add to list of handlers
	loop.handlers.add(*this);
}

Awaitable<QuadratureDecoder::Parameters> QuadratureDecoder_QDEC::change(int& delta) {
	return {this->tasks, &delta};
}

void QuadratureDecoder_QDEC::handle() {
	if (NRF_QDEC->EVENTS_REPORTRDY) {
		// clear pending interrupt flags at peripheral and NVIC
		NRF_QDEC->EVENTS_REPORTRDY = 0;
		clearInterrupt(QDEC_IRQn);

		this->acc += NRF_QDEC->ACCREAD;
		int poti = this->acc & ~3;
		if (poti != 0) {
			this->acc -= poti;
			int delta = poti >> 2;

			// resume all waiting coroutines
			this->tasks.resumeAll([delta](Parameters parameters) {
				*parameters.delta = delta;
				return true;
			});
		}
	}
}

} // namespace coco
