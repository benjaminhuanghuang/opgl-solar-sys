#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

class Model
{
public:
  Model(const std::string &objFile, const std::string &textureFile){}
  ~Model() {}

  void Draw(Shader shader) {}

  void LoadMesh(const std::string &fileName);

  void LoadTexture(const std::string &fileName);

  void Unload(){}
private:
  Mesh *mMesh;
  Texture *mTexture;
  // Name of shader specified by mesh
  Shader mShaderName;
};
