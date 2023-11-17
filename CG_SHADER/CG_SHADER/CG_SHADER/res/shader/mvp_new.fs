#version 330

layout(location = 0) out vec4 color;

//���̴� �ڵ忡�� ����ü ��� ����
struct DirectionalLight
{
	//���� �ڷῡ�� s_a�� �ش� (acolor * aintensity = s_a)
	vec3 lightColor; 
	float ambientIntensity;
};

//-- �Ʒ��� ���� ���ϰ� Material�� �Ӽ��� color�� ���ϴ� ��쵵 ������,
//-- ��ü�� diffuse color�� ambient/specular �÷��� ũ�� �ٸ��� �ʴٰ� �����Ͽ� ����ȭ ����
//-- ��, m_a = m_d & m_s = m_d �� ����
//-- m_d��? texture color

//struct Material {
//	vec3 ambient; //m_a
//	vec3 diffuse; //m_d
//	vec3 specular; //m_s
//	float shininess; //sh
//};
//uniform Material u_Material;

in vec2 v_TexCoord; //���ؽ� ���̴����� �Ѱܹ��� ������
in vec3 v_Normal;

uniform sampler2D u_Texture; //texture�� sampler2D Ÿ��
uniform DirectionalLight u_DirectionalLight;

void main()
{
	vec3 lightAmbient = u_DirectionalLight.lightColor * u_DirectionalLight.ambientIntensity;
	color = texture(u_Texture, v_TexCoord) * vec4(lightAmbient,1.0);
	//color = vec4(1.0, 0.0, 0.0, 1.0);
};