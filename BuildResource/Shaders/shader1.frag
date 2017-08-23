#version 330 core
out vec4 FragColor;
  
uniform vec4 ourColor;

in vec3 colorOutput;

void main()
{
    FragColor = ourColor;
}   