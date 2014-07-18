#ifndef VERTEXSHADER_HPP
#define VERTEXSHADER_HPP

#include"shader.hpp"

#include<GL/glew.h>

class VertexShader : public Shader
{
public:
	VertexShader() :
		Shader(GL_VERTEX_SHADER)
	{

	}

	VertexShader(const char *addr) :
		Shader(GL_VERTEX_SHADER, addr)
	{

	}

	virtual ~VertexShader()
	{

	}
};

#endif // VERTEXSHADER_HPP
