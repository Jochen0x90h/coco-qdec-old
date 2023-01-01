#pragma once

#include <coco/Coroutine.hpp>


namespace coco {

/**
 * Decoder for signals of incremental encoders such as digital potentiometers
 */
class QuadratureDecoder {
public:
	struct Parameters {
		int *delta;
	};


	virtual ~QuadratureDecoder();

	/**
	 * Wait for a change of the incremental encoder
	 * @param delta delta motion of incremental encoder
	 * @return use co_await on return value to await a change of the encoder
	 */
	[[nodiscard]] virtual Awaitable<Parameters> change(int& delta) = 0;
};

} // namespace coco
