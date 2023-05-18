#include <coco/Trigger.hpp>
#include <coco/QuadratureDecoder.hpp>
#include <coco/platform/Loop_emu.hpp>
#include <string>


namespace coco {

/**
	Implementation of an emulated rotary button (rotary knob with push button)
 */
class RotaryButton_emu : public Trigger, public QuadratureDecoder, public Loop_emu::GuiHandler {
public:
	/**
		Constructor
		@param loop event loop
		@param id unique id for gui
	*/
	RotaryButton_emu(Loop_emu &loop, int id);
	~RotaryButton_emu() override;

	[[nodiscard]] Awaitable<Trigger::Parameters> trigger(uint32_t &risingFlags, uint32_t &fallingFlags) override;
	[[nodiscard]] Awaitable<QuadratureDecoder::Parameters> change(int& delta) override;

protected:
	void handle(Gui &gui) override;

	int id;
	TaskList<Trigger::Parameters> triggerTasks;
	TaskList<QuadratureDecoder::Parameters> changeTasks;
};

} // namespace coco
