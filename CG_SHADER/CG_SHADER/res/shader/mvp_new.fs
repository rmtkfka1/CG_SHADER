#version 330

layout(location = 0) out vec4 color;

struct light
{

	vec3 lightColor; 
	float ambientIntensity;

	vec3 direction;
	float diffuseIntensity;
};


in vec2 v_TexCoord; 
in vec3 v_Normal;

uniform sampler2D u_texture;
uniform light u_light;
uniform vec3 control_color;


void main()
{
	vec3 lightAmbient = u_light.lightColor * u_light.ambientIntensity;

	float diffuseFactor = max(dot(normalize(v_Normal), normalize(u_light.direction)), 0.0);
	vec3 lightDiffuse = u_light.lightColor * u_light.diffuseIntensity * diffuseFactor;


	color = texture(u_texture, v_TexCoord)* vec4(lightAmbient+lightDiffuse,1.0) + vec4(control_color,1);


};