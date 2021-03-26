#include "Model.h"
#include "Shader.h"
#include "Texture.h"

using namespace std;

union Vertex
{
  float f;
  uint8_t b[4];
};

Model::Model(const string &path)
{
  LoadModel(path);
}

void Model::Draw(Shader shader)
{
  for (GLuint i = 0; i < mMeshes.size(); i++)
  {
    mMeshes[i].Draw(shader);
  }
}

void Model::LoadModel(const string &path)
{
  Assimp::Importer importer;
  const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

  if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
  {
    cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << endl;
    return;
  }

  mDirectory = path.substr(0, path.find_last_of('/'));
  ProcessNode(scene->mRootNode, scene);
}

void Model::ProcessNode(aiNode *node, const aiScene *scene)
{
  for (GLuint i = 0; i < node->mNumMeshes; i++)
  {
    aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
    mMeshes.push_back(ProcessMesh(mesh, scene));
  }

  for (GLuint i = 0; i < node->mNumChildren; i++)
  {
    ProcessNode(node->mChildren[i], scene);
  }
}

/*
  PosNormTex
*/
Mesh Model::ProcessMesh(aiMesh *mesh, const aiScene *scene)
{
  //== Load in the vertices
  std::vector<Vertex> vertices;
  vertices.reserve(mesh->mNumVertices * 8);
  for (GLuint i = 0; i < mesh->mNumVertices; i++)
  {
    // vertext
    vertices.emplace_back(mesh->mVertices[i].x);
    vertices.emplace_back(mesh->mVertices[i].y);
    vertices.emplace_back(mesh->mVertices[i].z);
    // normal
    vertices.emplace_back(mesh->mNormals[i].x);
    vertices.emplace_back(mesh->mNormals[i].y);
    vertices.emplace_back(mesh->mNormals[i].z);
    // texture coordinate
    if (mesh->mTextureCoords[0])
    {
      vertices.emplace_back(mesh->mTextureCoords[0][i].x);
      vertices.emplace_back(mesh->mTextureCoords[0][i].y);
    }
    else
    {
      vertices.emplace_back(0);
      vertices.emplace_back(0);
    }
  }
  //== Load in the indices
  std::vector<unsigned int> indices;
  for (GLuint i = 0; i < mesh->mNumFaces; i++)
  {
    aiFace face = mesh->mFaces[i];
    for (GLuint j = 0; j < face.mNumIndices; j++)
    {
      indices.emplace_back(face.mIndices[j]);
    }
  }
  //== Load texture
  vector<Texture> textures;

  if (mesh->mMaterialIndex >= 0)
  {
    aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
    vector<Texture> diffuseMaps = LoadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
    vector<Texture> specularMaps = LoadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
  }
  return Mesh(vertices.data(),vertices.size(), indices.data(), indices.size());
}

vector<Texture> Model::LoadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName)
{
  vector<Texture> textures;
  for (GLuint i = 0; i < mat->GetTextureCount(type); i++)
  {
    aiString str;
    mat->GetTexture(type, i, &str);
    GLboolean skip = false;

 
      Texture texture;
      string filename = directory + '/' + str;
      texture.Load(filename);
      mTextures.emplace_back(texture);
  }

  return textures;
}
