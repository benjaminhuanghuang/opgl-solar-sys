#include "ObjLoader.h"
#include "Util.h"
#include "VertexArray.h"

VertexArray* ObjLoader::LoadMesh(std::string const &filename)
{
  std::ifstream fin(filename.c_str());

  if (!fin.is_open())
  {
    std::cerr << "[ERROR]: Failed to open file: " << filename << std::endl;
    exit(EXIT_FAILURE);
  }

  // read file to
  std::vector<glm::vec3> positions;
  std::vector<glm::vec2> texCoords;
  std::vector<glm::vec3> normals;

  // put verext data to
  std::vector<GLfloat> vertices;
  std::vector<GLuint> indices;

  std::string line;
  int last = 0;

  while (std::getline(fin, line))
  {
    std::vector<std::string> tokens = Util::split(line, ' ');
    if (tokens.empty())
    {
      continue;
    }

    if (tokens[0] == "v")
    {
      positions.push_back(glm::vec3(stof(tokens[1]), stof(tokens[2]), stof(tokens[3])));
    }
    else if (tokens[0] == "vt")
    {
      texCoords.push_back(glm::vec2(stof(tokens[1]), stof(tokens[2])));
    }
    else if (tokens[0] == "vn")
    {
      normals.push_back(glm::vec3(stof(tokens[1]), stof(tokens[2]), stof(tokens[3])));
    }
    else if (tokens[0] == "f")
    {
      fin.seekg(last);
      vertices = std::vector<GLfloat>(8 * positions.size());
      break;
    }
    last = fin.tellg();
  }

  while (std::getline(fin, line))
  {
    std::vector<std::string> face = Util::split(line, ' ');
    if (face.empty() || face[0] != "f")
    {
      continue;
    }

    std::vector<std::string> v1 = Util::split(face[1], '/');
    std::vector<std::string> v2 = Util::split(face[2], '/');
    std::vector<std::string> v3 = Util::split(face[3], '/');

    ProcessVertex(v1, positions, texCoords, normals, vertices, indices);
    ProcessVertex(v2, positions, texCoords, normals, vertices, indices);
    ProcessVertex(v3, positions, texCoords, normals, vertices, indices);
  }

  return new VertexArray(vertices.data(), vertices.size(), indices.data(), indices.size());
}

void ObjLoader::ProcessVertex(std::vector<std::string> const &vertexData,
                              std::vector<glm::vec3> const &positions,
                              std::vector<glm::vec2> const &texCoords,
                              std::vector<glm::vec3> const &normals,
                              std::vector<GLfloat> &vertices,
                              std::vector<GLuint> &indices)
{
  GLuint idx = stoi(vertexData[0]) - 1;
  indices.push_back(idx);

  glm::vec3 position = positions[stoi(vertexData[0]) - 1];
  vertices[idx * 8] = position.x;
  vertices[idx * 8 + 1] = position.y;
  vertices[idx * 8 + 2] = position.z;

  glm::vec3 normal = normals[stoi(vertexData[2]) - 1];
  vertices[idx * 8 + 3] = normal.x;
  vertices[idx * 8 + 3 + 1] = normal.y;
  vertices[idx * 8 + 3 + 2] = normal.z;

  glm::vec2 texCoord = texCoords[stoi(vertexData[1]) - 1];
  vertices[idx * 8 + 6] = texCoord.x;
  vertices[idx * 8 + 6 + 1] = 1 - texCoord.y;
}