#include <coco/QuadratureDecoder.hpp>
#include <coco/platform/Loop_emu.hpp>
#include <string>


namespace coco {

/**
	Implementation of an emulated rotary knob
 */
class RotaryKnob_emu : public QuadratureDecoder, public Loop_emu::GuiHandler {
public:
	/**
		Constructor
		@param loop event loop
		@param id unique id for gui
	*/
	RotaryKnob_emu(Loop_emu &loop, int id);
	~RotaryKnob_emu() override;

	[[nodiscard]] Awaitable<Parameters> change(int& delta) override;

protected:
	void handle(Gui &gui) override;

	int id;
	TaskList<Parameters> changeTasks;
};

} // namespace coco
