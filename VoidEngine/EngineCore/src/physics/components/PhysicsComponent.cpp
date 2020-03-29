//STD Headers

//Library Headers

//Void Engine Headers
#include "physics/components/PhysicsComponent.h"

namespace core {
	TYPE_INFO_IMPL(PhysicsComponent)

	ENABLE_FACTORY(PhysicsComponent, Component)

	PhysicsComponent::PhysicsComponent() : m_Velocity(), Force(), Mass(1), InverseMass(1),
		GravityScale(1), Density(1), Restitution(.5), IsStatic(false) {

	}

	PhysicsComponent::~PhysicsComponent() {

	}

	void PhysicsComponent::Initialize() {
		if (ConfigData.find("isStatic") != ConfigData.end()) {
			IsStatic = ConfigData["isStatic"].get<bool>();
		}
		if (ConfigData.find("mass") != ConfigData.end()) {
			Mass = ConfigData["mass"].get<float>();
			InverseMass = (Mass == 0.0f) ? 0 : 1 / Mass;
		}
		if (ConfigData.find("gravityScale") != ConfigData.end()) {
			GravityScale = ConfigData["gravityScale"].get<float>();
		}
		if (ConfigData.find("restitution") != ConfigData.end()) {
			Restitution = ConfigData["restitution"].get<float>();
		}

		if (IsStatic) {
			Mass = InverseMass = 0;
		}
	}

	void PhysicsComponent::ApplyForce(const math::Vector3& force) {
		Force += force;
	}

	void PhysicsComponent::SetMass(float mass) {
		Mass = mass;
		InverseMass = (mass == 0) ? 0 : 1 / mass;
	}

	float PhysicsComponent::GetMass() const {
		return Mass;
	}

	float PhysicsComponent::GetInverseMass() const {
		return InverseMass;
	}

	math::Vector3 PhysicsComponent::GetForce() const {
		return Force;
	}

	void PhysicsComponent::ClearForce() {
		Force.X = Force.Y = Force.Z = 0;
	}

	math::Vector3 PhysicsComponent::GetVelocity() const {
		return m_Velocity;
	}

	void PhysicsComponent::AddVelocity(const math::Vector3& velocity) {
		m_Velocity += velocity;
	}

	float PhysicsComponent::GetRestitution() const {
		return Restitution;
	}

	float PhysicsComponent::GetGravityScale() const {
		return GravityScale;
	}

	bool PhysicsComponent::GetIsStatic() const {
		return IsStatic;
	}

}