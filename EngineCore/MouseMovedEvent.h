#pragma once
//STD Headers

//Library Headers

//Void Engine Headers
#include "Event.h"
#include "Vector.h"

namespace core {
	class MouseMovedEvent : public Event {
	public:
		/**
		 * Constructor
		 */
		MouseMovedEvent(int xPos, int yPos);

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

		math::Vector2 Position;
	};
}
