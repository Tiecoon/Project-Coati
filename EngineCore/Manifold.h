#pragma once
//STD Headers

//Library Headers

//Void Engine Headers
#include "Vector.h"

namespace core {

	class ColliderComponent;

	/**
	 * Manifold is the struct generated by collision detection functions
	 * that destribes the nature of the detected collision
	 */
	struct Manifold {
		/**
		 * Constructor
		 */
		Manifold();

		/** First collider involved in collision */
		ColliderComponent* ColliderA;
		
		/** Second collider involved in collision */
		ColliderComponent* ColliderB;

		/** Distance the two objects are 
		 * intersecting along the CollisionNormal 
		 */
		float PenetrationDistance;

		/** Vector of resolution */
		math::Vector3 CollisionNormal;

	};

}

