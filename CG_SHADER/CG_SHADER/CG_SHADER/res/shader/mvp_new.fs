#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord; //버텍스 셰이더에서 넘겨받은 데이터
in vec3 v_Normal;

uniform sampler2D test; //texture는 sampler2D 타입

void main()
{
	//--빨간색으로 표시해 보기
	//color = vec4(1.0, 0.0, 0.0, 1.0);

	//--normal을 색상으로 표시해 보기
	vec3 normalColor = (v_Normal + 1.0) / 2.0;
	color = vec4(normalColor, 1.0);

	//--uvchecker 입혀 보기, 왜 어떤 부분은 검은색으로 보일까?
	color = texture(test, v_TexCoord);
	//color = v_Color;
};