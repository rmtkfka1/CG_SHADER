#version 330 core

out vec3 color; 
in vec3 v_color;

uniform sampler2D test;

void main()
{
	color = vec3(1.0f,0,0);
};