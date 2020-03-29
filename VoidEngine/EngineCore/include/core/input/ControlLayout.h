#pragma once
//STD Headers
#include <unordered_map>
#include <unordered_set>

//Library Headers

//Void Engine Headers
#include "utils/resource/JsonResource.h"

#include "core/input/AxisInputAction.h"
#include "core/input/InputAction.h"
#include "core/input/InputAxis.h"
#include "core/input/definitions/AxisInput.h"
#include "core/input/definitions/KeyboardInput.h"
#include "core/input/definitions/MouseInput.h"
#include "core/input/definitions/GamepadInput.h"

namespace core {

	class ControlLayout : public utils::JsonResource {
	public:
		/**
		 * Constructor
		 */
		ControlLayout(const std::string& filePath);

		/**
		 * Allows the resource to be intialized after loading.
		 */
		virtual void Initialize() override;

		void UpdateAxis(AxisInputAction upate);

		std::vector<AxisInputAction> PollAxes();

		AxisInputAction PollAxis(const utils::Name& axisName);


		InputAction GetActionMapping(const KeyboardInput& input) const;
		InputAction GetActionMapping(const MouseInput& input) const;
		InputAction GetActionMapping(const GamepadInput& input) const;

		/**
		 * Dummy function to allow template deduction. DO NOT CALL
		 */
		InputAction GetActionMapping(const AxisInput& input) const;

		AxisInputAction GetAxisMapping(const KeyboardInput& input) const;
		AxisInputAction GetAxisMapping(const MouseInput& input) const;
		AxisInputAction GetAxisMapping(const GamepadInput& input) const;
		AxisInputAction GetAxisMapping(const AxisInput& input) const;

		bool IsBound(const KeyboardInput& input) const;
		bool IsBound(const MouseInput& input) const;
		bool IsBound(const GamepadInput& input) const;
		bool IsBound(const AxisInput& input) const;

		bool IsBoundToAction(const KeyboardInput& input) const;
		bool IsBoundToAction(const MouseInput& input) const;
		bool IsBoundToAction(const GamepadInput& input) const;
		bool IsBoundToAction(const AxisInput& input) const;

		bool IsBoundToAxis(const KeyboardInput& input) const;
		bool IsBoundToAxis(const MouseInput& input) const;
		bool IsBoundToAxis(const GamepadInput& input) const;
		bool IsBoundToAxis(const AxisInput& input) const;

	private:
		
		void LoadActionMappings();
		void LoadAxisMappings();

		std::unordered_map<utils::Name, std::shared_ptr<InputAxis>> m_InputAxes;

		/** Bindings for buttons to Actions */
		std::unordered_map<KeyboardButton, utils::Name> m_KeyboardActionBindings;
		std::unordered_map<MouseButton, utils::Name> m_MouseActionBindings;
		std::unordered_map<GamepadButton, utils::Name> m_GamepadActionBindings;

		/** Bindings for buttons to Axes */
		std::unordered_map<KeyboardButton, std::pair<utils::Name, float>> m_KeyboardAxisBindings;
		std::unordered_map<MouseButton, std::pair<utils::Name, float>> m_MouseAxisBindings;
		std::unordered_map<GamepadButton, std::pair<utils::Name, float>> m_GamepadAxisBindings;

		/** Bindings for analog axes to AxisActions */
		std::unordered_map<RawAxisType, std::pair<utils::Name, float>> m_AnalogAxisBindings;
	};


}

