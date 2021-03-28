#include "Shader.h"
#include "Entity.h"
#include "SolarSystem.h"
#include "Renderer.h"
#include "Texture.h"
#include "VertexArray.h"
#include "MeshComponent.h"

MeshComponent::MeshComponent(Entity *owner) : Component(owner), mVertexArray(nullptr), mTexture(nullptr)
{
  // add MeshComponent to system
  mOwner->GetSolarSystem()->GetRenderer()->AddMeshComp(this);
}

MeshComponent::~MeshComponent()
{
  mOwner->GetSolarSystem()->GetRenderer()->RemoveMeshComp(this);
}

void MeshComponent::Draw(Shader *shader)
{
  // Set the world transform
  shader->SetMatrixUniform("uWorldTransform", mOwner->GetWorldTransform());
  // Set specular power
  //shader->SetFloatUniform("uSpecPower", mMesh->GetSpecPower());
  // Set the active texture
  mTexture->SetActive();

  // Set the mesh's vertex array as active
  mVertexArray->SetActive();
  // Draw
  glDrawElements(GL_TRIANGLES, mVertexArray->GetNumIndices(), GL_UNSIGNED_INT, nullptr);
}
