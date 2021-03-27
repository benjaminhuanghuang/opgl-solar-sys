#include "Model.h"
#include "Shader.h"
#include "Texture.h"
#include "ObjLoader.h"

using namespace std;

Model::Model(const std::string &objFile, const std::string &textureFile)
{
  LoadMesh(objFile);
  LoadTexture(textureFile);
}
Model::~Model(){

}
void Model::Draw(Shader shader)
{
  // for (GLuint i = 0; i < mMeshes.size(); i++)
  // {
  //   mMeshes[i].Draw(shader);
  // }
}

/*
  Load vertext array from .obj file
*/
void Model::LoadMesh(const string &fileName)
{
  mMesh = ObjLoader::LoadMesh(fileName);
}


void Model::LoadTexture(const string &fileName)
{
  mTexture = new Texture();
  mTexture->Load(fileName);
}



void Model::Unload()
{
	delete mMesh;
	mMesh = nullptr;
}