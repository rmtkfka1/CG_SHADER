#version 330 core

out vec3 color; 
in vec3 v_color;

uniform vec4 u_color;

void main()
{
	color = vec3(u_color.x,u_color.y,u_color.z);
};