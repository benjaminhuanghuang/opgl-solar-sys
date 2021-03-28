#include "Shader.h"
#include "SpriteComponent.h"
#include "Entity.h"
#include "SolarSystem.h"
#include "Util.h"
#include "Renderer.h"

SpriteComponent::SpriteComponent(Entity *owner, int drawOrder) : Component(owner), 
                                                                mTexture(nullptr), 
																																mDrawOrder(drawOrder), 
																																mTexWidth(0), 
																																mTexHeight(0)
{
	mOwner->GetSolarSystem()->GetRenderer()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetSolarSystem()->GetRenderer()->RemoveSprite(this);
}

void SpriteComponent::Draw(Shader *shader)
{
	if (mTexture)
	{
		// Scale the quad by the width/height of texture
	  glm::mat4 scaleMat = Util::CreateScale(
				static_cast<float>(mTexWidth),
				static_cast<float>(mTexHeight),
				1.0f);

		glm::mat4 world = scaleMat * mOwner->GetWorldTransform();

		// Since all sprites use the same shader/vertices,
		// the game first sets them active before any sprite draws

		// Set world transform
		shader->SetMatrixUniform("uWorldTransform", world);
		// Set current texture
		mTexture->SetActive();
		// Draw quad
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}
}

void SpriteComponent::SetTexture(Texture* texture)
{
	mTexture = texture;
	// Set width/height
	mTexWidth = texture->GetWidth();
	mTexHeight = texture->GetHeight();
}
