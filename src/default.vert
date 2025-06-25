#version 330 core
// position/ cords
layout (location = 0) in vec3 aPos;
//color
layout (location = 1) in vec3 aColor;

//outputs the color for the fragment shader
out vec3 color;

//controls the scale of the vertices
uniform float scale;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;



void main()
{
   //outputs the positions and coordinates of the vertices
   gl_Position = vec4(aPos.x + (aPos.x*scale), aPos.y + (aPos.y*scale), aPos.z + (aPos.z * scale), 1.0);
   //model * view * proj* vec4(aPos, 1.0);
   //
   //assigns thbe colors from the vertex data to "color"
   color = aColor;
}