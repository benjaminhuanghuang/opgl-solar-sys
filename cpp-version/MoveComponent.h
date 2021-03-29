#pragma once
#include "Component.h"

class MoveComponent : public Component
{
public:
	// Lower update order to update first
	MoveComponent(class Entity* owner, int updateOrder = 10);

	void Update(float deltaTime) override;
	
	float GetAngularSpeed() const { return mAngularSpeed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	

	float GetOribtSpeed() const { return mOrbitSpeed; }
	
	void SetOrbitSpeed(float speed) { mOrbitSpeed = speed; }


private:
	// start rotation (radians/second)
	float mAngularSpeed;
	// start orbit speed (units/second)
	float mOrbitSpeed;
};
