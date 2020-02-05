#pragma once
//STD Headers

//Library Headers

//Void Engine Headers
#include "math/Vector.h"
#include "utils/factory/Factory.h"
#include "utils/factory/FactoryConstructible.h"

namespace core {
	
	class Collider : public utils::FactoryConstructible {
		/**
		 * Declare custom RTTI support
		 */
		TYPE_INFO_DECL(Collider)

	public:
		/**
		 * Constructor
		 */
		Collider();

		/**
		 * Applies configuration settings
		 */
		virtual void Initialize() = 0;

		/**
		 * Collision Layer Accessor
		 */
		unsigned GetCollisionLayer();

	};

}
