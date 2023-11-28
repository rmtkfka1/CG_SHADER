#version 330

//Model Ŭ������ ���� 3���� ��ǥ, 2���� �ؽ�ó ��ǥ, 3���� ���� ���� �����͸� �Ѱ��ִ� ���� �� �� ����
//�̷� ������ �Ѿ������ �츮�� vertex buffer layout�� ���� ��������
layout(location = 0) in vec3 position; 
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 normal;

out vec2 v_TexCoord; //���ؽ� ���̴����� �߰������� ����ϴ� ������(varying)
out vec3 v_Normal;
out vec3 v_worldPosition;

uniform mat4 u_model; //world ��ȯ ���
uniform mat4 u_view; //ī�޶� ���� ��ȭ�� View ���
uniform mat4 u_proj; //CPU���� ���޵� (glm ���̺귯���� ���� ������) ���� ���

void main()
{

	gl_Position = u_proj * u_view * u_model * vec4(position,1.0); // ���� ��ġ�� ���� ��İ� ��
	v_TexCoord = texCoord; //vertex ��ȯ�� ���� �ٲ��� �����Ƿ� �״�� �Ѱ��ָ� ��
	v_Normal = mat3(transpose(inverse(u_model)))*normal;

	v_worldPosition = (u_model * vec4(position, 1.0)).xyz; //������ World space ��ǥ

};