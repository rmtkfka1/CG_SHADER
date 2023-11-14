#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord; //���ؽ� ���̴����� �Ѱܹ��� ������
in vec3 v_Normal;

uniform sampler2D test; //texture�� sampler2D Ÿ��

void main()
{
	//--���������� ǥ���� ����
	//color = vec4(1.0, 0.0, 0.0, 1.0);

	//--normal�� �������� ǥ���� ����
	vec3 normalColor = (v_Normal + 1.0) / 2.0;
	color = vec4(normalColor, 1.0);

	//--uvchecker ���� ����, �� � �κ��� ���������� ���ϱ�?
	color = texture(test, v_TexCoord);
	//color = v_Color;
};