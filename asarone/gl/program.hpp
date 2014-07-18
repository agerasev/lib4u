#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include"shader.hpp"
#include<iostream>

class Program
{
private:
	GLuint id;

	void logLinking() {
		int link_ok;
		glGetProgramiv(id, GL_LINK_STATUS, &link_ok);
		if(!link_ok) {
			std::cout << "Error attach shaders" << "\n";
		}
	}

	void logAttribute(GLint attrib, const GLchar *name) {
		if(attrib == -1)
		{
			std::cout << "Could not bind attribute " << name << "\n";
		}
	}
	void logUniform(GLint unif, const GLchar *name) {
		if(unif == -1)
		{
			std::cout << "Could not bind uniform " << name << "\n";
		}
	}

public:

	Program() {
		id = glCreateProgram();
	}
	virtual ~Program() {
		glDeleteProgram(id);
	}

	void attach(Shader &sh) {
		glAttachShader(id,sh.getID());

	}
	void link() {
		glLinkProgram(id);
		logLinking();
	}

	virtual void enable() {
		glUseProgram(id);
	}
	virtual void disable() {
		glUseProgram(0);
	}

	GLint getAttribute(const GLchar *name) {
		GLint attrib = glGetAttribLocation(id, name);
		logAttribute(attrib,name);
		return attrib;
	}
	GLint getUniform(const GLchar *name) {
		GLint unif = glGetUniformLocation(id, name);
		logUniform(unif,name);
		return unif;
	}
};

#endif // PROGRAM_HPP
