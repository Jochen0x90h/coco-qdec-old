#include "RotaryButton_emu.hpp"
#include "RotaryButton.hpp"
#include <iostream>


namespace coco {

RotaryButton_emu::RotaryButton_emu(Loop_emu &loop, int id)
	: id(id)
{
	loop.guiHandlers.add(*this);
}

RotaryButton_emu::~RotaryButton_emu() {
}

Awaitable<Trigger::Parameters> RotaryButton_emu::trigger(uint32_t &risingFlags, uint32_t &fallingFlags) {
	return {this->triggerTasks, &risingFlags, &fallingFlags};
}

Awaitable<QuadratureDecoder::Parameters> RotaryButton_emu::change(int& delta) {
	return {this->changeTasks, &delta};
}

void RotaryButton_emu::handle(Gui &gui) {
	auto result = gui.widget<RotaryButton>(this->id, true);
	if (result.button) {
		bool button = *result.button;
		this->triggerTasks.resumeAll([button](Trigger::Parameters &p) {
			if (button) {
				if (*p.risingFlags & 1) {
					*p.risingFlags = 1;
					*p.fallingFlags = 0;
					return true;
				}
			} else {
				if (*p.fallingFlags & 1) {
					*p.risingFlags = 0;
					*p.fallingFlags = 1;
					return true;
				}
			}
			return false;
		});
	}
	if (result.delta) {
		int delta = *result.delta;
		std::cout << delta << std::endl;
		this->changeTasks.resumeAll([delta](QuadratureDecoder::Parameters &p) {
			*p.delta = delta;
			return true;
		});
	}
}

} // namespace coco
