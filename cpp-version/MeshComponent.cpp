#include "MeshComponent.h"
#include "Shader.h"
#include "Mesh.h"
#include "Entity.h"
#include "SolarSystem.h"
#include "Renderer.h"
#include "Texture.h"
#include "VertexArray.h"

MeshComponent::MeshComponent(Entity *owner) : Component(owner), mMesh(nullptr)
{
	mOwner->GetSolarSystem()->GetRenderer()->AddMeshComp(this);
}

MeshComponent::~MeshComponent()
{
	mOwner->GetSolarSystem()->GetRenderer()->RemoveMeshComp(this);
}

void MeshComponent::Draw(Shader *shader)
{
	if (mMesh)
	{
		// Set the world transform
		shader->SetMatrixUniform("uWorldTransform",
														 mOwner->GetWorldTransform());
		// Set specular power
		shader->SetFloatUniform("uSpecPower", mMesh->GetSpecPower());
		// Set the active texture
		Texture *t = mMesh->GetTexture(mTextureIndex);
		if (t)
		{
			t->SetActive();
		}
		// Set the mesh's vertex array as active
		VertexArray *va = mMesh->GetVertexArray();
		va->SetActive();
		// Draw
		glDrawElements(GL_TRIANGLES, va->GetNumIndices(), GL_UNSIGNED_INT, nullptr);
	}
}
