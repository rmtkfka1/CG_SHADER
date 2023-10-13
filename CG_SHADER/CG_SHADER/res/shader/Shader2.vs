#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 color;

out vec3 v_color;

uniform mat4 u_model;
void main()
{
	gl_Position = u_model*position ; 
	v_color = color;

};
