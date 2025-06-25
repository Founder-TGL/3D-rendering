#include<iostream>
#include<glad/glad.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<GLFW/glfw3.h>
#include "stb_image.h"

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include <math.h>



// Vertices coordinates
GLfloat vertices[] =
{
	-0.5f, -0.5f, 0.0f, 		0.8f, 0.3f, 0.02f, 		0.0f, 0.0f,// Lower left corner
	-0.5f, 0.5f, 0.0f, 			0.8f, 0.3f, 0.02f, 		0.0f, 1.0f,// Upper left corner
	 0.5f, 0.5f, 0.0f, 			1.0f, 0.6f, 0.32f, 		1.0f, 1.0f,// Upper right corner
	 0.5f, -0.5f, 0.0f,			0.9f, 0.45f, 0.17f, 	1.0f, 1.0f// Lower right corner

};

// Indices for vertices order
GLuint indices[] =
{
	0,2,1,
	0,3,2
};

const unsigned int width = 800;
const unsigned int height = 800;


int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL window ;3", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);



	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");



	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	// //texture
	
	// int widthImg, heightImg, numColCh;
	// stbi_set_flip_vertically_on_load(true);
	// unsigned char* bytes = stbi_load("C:/rust.jpg", &widthImg, &heightImg, &numColCh, 0);
	// if (!bytes) {
    // std::cout << "Failed to load texture!" << std::endl;
	// std::cout << "STB Error: " << stbi_failure_reason() << std::endl;
    // return -1;
	// } std::cout << "passed checkpoint actual\n";

	// GLuint texture;
	// glGenTextures(0, &texture);
	// glActiveTexture(GL_TEXTURE0);
	// glBindTexture(GL_TEXTURE_2D, texture);

	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// glTexImage2D(GL_TEXTURE_2D, 0 , GL_RGB, widthImg, heightImg, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
	// glGenerateMipmap(GL_TEXTURE_2D);

	// stbi_image_free(bytes);
	// glBindTexture(GL_TEXTURE_2D, 0);

	// GLuint tex0Uni = glGetUniformLocation(shaderProgram.ID, "tex0");
	// shaderProgram.Activate();
	// glUniform1i(tex0Uni, 0);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{ 
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();

		// glm::mat4 model = glm::mat4(1.0f);
		// glm::mat4 view = glm::mat4(1.0f);
		// glm::mat4 proj = glm::mat4(1.0f);
		// view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
		// proj = glm::perspective(glm::radians(45.0f), (float)(width/height), 0.1f, 100.0f);

		// int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		// glUniformMatrix4fv(modelLoc,1, GL_FALSE, glm::value_ptr(model));
		// int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		// glUniformMatrix4fv(viewLoc,1, GL_FALSE, glm::value_ptr(view));
		// int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		// glUniformMatrix4fv(projLoc,1, GL_FALSE, glm::value_ptr(proj));

		glUniform1f(uniID, 0.5f);
		// glBindTexture(GL_TEXTURE_2D, texture);
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 6 , GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	glDeleteTextures(1, &texture);
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}