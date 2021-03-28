// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include <vector>
#include <string>
#include "VertexArray.h"

class Mesh
{
public:
	Mesh();
	~Mesh();

	// Load/unload mesh
	bool Load(const std::string &fileName, class Renderer *renderer);
	void Unload();
	// Get the vertex array associated with this mesh
	VertexArray *GetVertexArray() { return mVertexArray; }
	// Get a texture from specified index
	class Texture *GetTexture(size_t index);
	// Get name of shader
	const std::string &GetShaderName() const { return mShaderName; }
	// Get file name
	const std::string &GetFileName() const { return mFileName; }


private:
	// Textures associated with this mesh
	std::vector<class Texture *> mTextures;
	// Vertex array associated with this mesh
	VertexArray *mVertexArray;
	// Name of shader specified by mesh
	std::string mShaderName;
	// Name of mesh file
	std::string mFileName;
};