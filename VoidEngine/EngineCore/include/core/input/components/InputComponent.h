#pragma once
//STD Headers
#include <unordered_map>
#include <string>

//Library Headers

//Void Engine Headers
#include "core/gameplay_framework/Component.h"
#include "core/input/InputAction.h"
#include "core/input/InputAxis.h"

namespace core {

	class InputComponent : public Component {
		/**
		 * Declare custom RTTI support
		 */
		TYPE_INFO_DECL(InputComponent)

	public:
		/**
		 * Constructor
		 */
		InputComponent();

		/**
		 * Applies component data to this object
		 */
		void Initialize() override;

		/**
		 * Allows parent to set up input component with callback functions
		 * @param actionName The name of the input action being bound
		 * @param type Whether this binding should be activated on key press or release
		 * @param callback The callback function for this binding
		 */
		void BindAction(const std::string& actionName, ActionType type, std::function<void(float)> callback);

		/**
		 * Allows parent to set up input component with callback functions
		 * @param actionName The name of the input action being bound
		 * @param type Whether this binding should be activated on key press or release
		 * @param callback The callback function for this binding
		 * @note callback arguments are AxisReading, DeltaTime
		 */
		void BindAxis(const std::string& axisName, std::function<void(float, float)> callback);

		/**
		 * Function to allow this component process input actions
		 * @param input The input action to resolve
		 * @param deltaTime The current time step
		 */
		void Input(const InputAction& input, float deltaTime) override;

		/**
		 * Function to allow this component to process axis input
		 * @param input The axis action to resolve
		 * @param deltaTime The current time step
		 */
		void Input(const AxisInputAction& input, float deltaTime) override;

	private:
		/** Component bindings for InputActions */
		std::unordered_map<InputAction, std::function<void(float)>> m_ActionMappings;

		/** Component bindings for InputAxisActions */
		std::unordered_map<AxisInputAction, std::function<void(float, float)>> m_AxisMappings;
	};

}

