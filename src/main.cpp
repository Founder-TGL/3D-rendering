#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

using namespace std; 

// Vertex Shader source code  (FIGURE OUT HOW THIS WORKS LATER)
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main()
{   
    //initializes glfw so everything can be used
    glfwInit();


    
    //informs glfw of the version we are using
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //tells glfw to only use the modern functions, so nothing outdated or old 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLfloat vertices[] = 
    {
        -0.5, -0.5 * float(sqrt(3)) / 3, 0.0f,
        0.5, -0.5 * float(sqrt(3)) /3, 0.0f,
        0.0, 0.5 * float(sqrt(3)) / 2, 0.0f
    };


    //creates a window object
    GLFWwindow* window = glfwCreateWindow(800,800, "test Window", NULL , NULL);
    //error checks to ensure the window popped up
    if(window == NULL){
        cout<< "failed to create GLFW window";
        glfwTerminate();
        return -1;
    }

    //brings the window to the current context so it may be edited (i beleive)
    glfwMakeContextCurrent(window);

    //loads glad so it may configure GL
    gladLoadGL();

    //specify the viewport of OpenGL in the window
    glViewport(0,0,800,800);


    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);



    GLuint VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //specify the color of the background 
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    //cleans the back buffer and assigns it a color
    glClear(GL_COLOR_BUFFER_BIT);
    //swaps the back and front buffer
    glfwSwapBuffers(window);

    //while the window is opened it polls events (deals with all GLFW events)
    while(!glfwWindowShouldClose(window)){
        //specify the color of the background 
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        //cleans the back buffer and assigns it a color
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);


        glfwPollEvents();
    }
    
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    //ends program
    glfwTerminate();
    return 0;
}