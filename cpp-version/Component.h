#pragma once
#include <cstdint>
#include "Entity.h"

/*
  Feature of entity, 
*/
class Component
{
public:
  // Constructor
  // (the lower the update order, the earlier the component updates)
  Component(class Entity *owner, int updateOrder = 100);
  // Destructor
  virtual ~Component();
  // Update this component by delta time
  virtual void Update(float deltaTime);

  	// Called when world transform changes
	virtual void OnUpdateWorldTransform() {}
  
  class Entity *GetOwner()
  {
    return mOwner;
  }
  int GetUpdateOrder() const
  {
    return mUpdateOrder;
  }

protected:
  // Owning actor
  class Entity *mOwner;
  // Update order of component
  int mUpdateOrder;
};
