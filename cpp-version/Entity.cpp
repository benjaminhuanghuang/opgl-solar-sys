#include "Entity.h"
#include "Constants.h"
#include "Math.h"

Entity::Entity(SolarSystem *solar) : mPosition(glm::vec3(0)),
                                     mScale(1.0f),
                                     mRotX(0),
                                     mRotY(0),
                                     mRotZ(0),
                                     mSolarSys(solar)

{
  solar->AddEntity(this);
}

Entity::~Entity()
{
  mSolarSys->RemoveEntity(this);
  // Need to delete components
  // Because ~Component calls RemoveComponent, need a different style loop
  while (!mComponents.empty())
  {
    delete mComponents.back();
  }
}

void Entity::Update(float deltaTime)
{

  ComputeWorldTransform();

  UpdateComponents(deltaTime);

  ComputeWorldTransform();
}

void Entity::UpdateComponents(float deltaTime)
{
  for (auto comp : mComponents)
  {
    comp->Update(deltaTime);
  }
}

void Entity::ComputeWorldTransform()
{

  // // Scale, then rotate, then translate
  mWorldTransform  = Math::CreateTransformationMatrix(mPosition, mRotX, mRotY, mRotZ, mScale);

  // Inform components world transform updated
  for (auto comp : mComponents)
  {
    comp->OnUpdateWorldTransform();
  }
}
