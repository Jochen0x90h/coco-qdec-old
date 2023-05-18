#include "RotaryKnob_emu.hpp"
#include "RotaryButton.hpp"
#include <iostream>


namespace coco {

RotaryKnob_emu::RotaryKnob_emu(Loop_emu &loop, int id)
	: id(id)
{
	loop.guiHandlers.add(*this);
}

RotaryKnob_emu::~RotaryKnob_emu() {
}

Awaitable<QuadratureDecoder::Parameters> RotaryKnob_emu::change(int& delta) {
	return {this->changeTasks, &delta};
}

void RotaryKnob_emu::handle(Gui &gui) {
	auto result = gui.widget<RotaryButton>(this->id, false);
	if (result.delta) {
		int delta = *result.delta;
		std::cout << delta << std::endl;
		this->changeTasks.resumeAll([delta](Parameters &p) {
			*p.delta = delta;
			return true;
		});
	}
}

} // namespace coco
