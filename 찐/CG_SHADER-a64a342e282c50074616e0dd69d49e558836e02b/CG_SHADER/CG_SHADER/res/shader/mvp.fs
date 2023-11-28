#version 330

layout(location = 0) out vec4 color;

in vec2 v_TexCoord; //���ؽ� ���̴����� �Ѱܹ��� ������
in vec3 v_Normal;

uniform sampler2D u_texture; //texture�� sampler2D Ÿ��
uniform vec3 control_color;

void main()
{
	//--���������� ǥ���� ����
	//color = vec4(1.0, 0.0, 0.0, 1.0);

	//--normal�� �������� ǥ���� ����
	vec3 normalColor = (v_Normal + 1.0) / 2.0;
	color = vec4(normalColor, 1.0);

	//--uvchecker ���� ����, �� � �κ��� ���������� ���ϱ�?
	color = texture(u_texture, v_TexCoord) + vec4(control_color,0);

	//color = v_Color;
};