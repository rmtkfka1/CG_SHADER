#version 330

layout(location = 0) out vec4 color;

//셰이더 코드에서 구조체 사용 가능
struct DirectionalLight
{
	//강의 자료에서 s_a에 해당 (acolor * aintensity = s_a)
	vec3 lightColor; 
	float ambientIntensity;
};

//-- 아래와 같이 상세하게 Material의 속성별 color를 정하는 경우도 있지만,
//-- 물체의 diffuse color와 ambient/specular 컬러가 크게 다르지 않다고 가정하여 간략화 가능
//-- 즉, m_a = m_d & m_s = m_d 로 가정
//-- m_d는? texture color

//struct Material {
//	vec3 ambient; //m_a
//	vec3 diffuse; //m_d
//	vec3 specular; //m_s
//	float shininess; //sh
//};
//uniform Material u_Material;

in vec2 v_TexCoord; //버텍스 셰이더에서 넘겨받은 데이터
in vec3 v_Normal;

uniform sampler2D u_Texture; //texture는 sampler2D 타입
uniform DirectionalLight u_DirectionalLight;

void main()
{
	vec3 lightAmbient = u_DirectionalLight.lightColor * u_DirectionalLight.ambientIntensity;
	color = texture(u_Texture, v_TexCoord) * vec4(lightAmbient,1.0);
	//color = vec4(1.0, 0.0, 0.0, 1.0);
};