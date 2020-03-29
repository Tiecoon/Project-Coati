#pragma once
//STD Headers

//Library Headers

//Void Engine Headers
#include "Event.h"
#include "input/definitions/MouseInput.h"

namespace core {
	class MouseButtonEvent : public Event {
	public:
		/**
		 * Constructor
		 */
		MouseButtonEvent(MouseInput& input);

		/**
		 * Virtual function to query type of Event object
		 */
		utils::Name GetEventType() const override;

		/**
		 * Virtual function to query category of Event object
		 */
		virtual EventCategory GetEventCategory() const override;

		/**
		 * Static function to get EventType info from C++ type info
		 */
		static utils::Name GetStaticEventType() /** override */;

		/** The input this event is reporting */
		MouseInput Input;
	};
}

