#include "SolarSystem.h"
#include "Entity.h"
#include "Constants.h"
#include "Util.h"

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
  mWorldTransform = Util::CreateTransformationMatrix(mPosition, mRotX, mRotY, mRotZ, mScale);

  // Inform components world transform updated
  for (auto comp : mComponents)
  {
    comp->OnUpdateWorldTransform();
  }
}
void Entity::AddComponent(Component *component)
{
  // Find the insertion point in the sorted vector
  // the lower the update order, the earlier the component updates)
  int myOrder = component->GetUpdateOrder();
  auto iter = mComponents.begin();
  for (; iter != mComponents.end(); ++iter)
  {
    if (myOrder < (*iter)->GetUpdateOrder())
    {
      break;
    }
  }
  // Inserts element before the first element with a order higher than me
  mComponents.insert(iter, component);
}

void Entity::RemoveComponent(Component *component)
{
  auto iter = std::find(mComponents.begin(), mComponents.end(), component);
  if (iter != mComponents.end())
  {
    mComponents.erase(iter);
  }
}
