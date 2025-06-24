#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    // Shader program ID
    unsigned int ID;

    // Constructor: read and build shader from file paths
    Shader(const char* vertexPath, const char* fragmentPath);

    // Use/activate the shader
    void Activate() const;

    // Delete the shader program
    void Delete();

    // Utility functions to set uniforms
    void SetMat4(const std::string& name, const glm::mat4& mat) const;
};

#endif
