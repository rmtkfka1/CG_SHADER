#pragma once
class Cube
{

public:

	Cube();
	~Cube();

	void Init(vec3 center, float size , int mode); // mode ==0 솔리드  , mode ==1 와이어
	void Update();
	void Render();

	

protected:

	vec3 m_center{}; // center pos 
	float m_size{}; // 사이즈 값 

	int m_mode; // 와이어 /솔리드

	VAO m_vao;
	VBO m_vbo; 
	IBO m_ibo;




};

