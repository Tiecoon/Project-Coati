//STD Headers

//Library Headers


//Coati Headers
#include "GenericInput.h"

namespace EngineCore {
	//tors

	bool GenericInput::operator==(const GenericInput& other) const {
		return (this->Button == other.Button && this->State == other.State);
	}

	GenericInput::GenericInput( unsigned button, ButtonState state, EngineUtilities::GameTime time)
		: Button(button), State(state), TimeStamp(time) {


	}

	unsigned GenericInput::GetButton() const {
		return Button;
	}

	ButtonState GenericInput::GetButtonState() const {
		return State;
	}

	EngineUtilities::GameTime GenericInput::GetTimeStamp() const {
		return TimeStamp;
	}

	std::size_t GenericInput::Hash() const {
		return static_cast<std::size_t>(GetTimeStamp());
	}

}