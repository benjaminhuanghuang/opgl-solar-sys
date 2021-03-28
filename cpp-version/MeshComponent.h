
#pragma once

#include "Component.h"
#include <cstddef>

class MeshComponent : public Component
{
public:
	MeshComponent(class Entity *owner);
	~MeshComponent();

	// Draw this mesh component
	virtual void Draw(class Shader *shader);
	
  // Set the mesh/texture index used by mesh component
	virtual void SetMesh(class Mesh *mesh) { mMesh = mesh; }

protected:
	class Mesh *mMesh;
	bool mVisible;
};
