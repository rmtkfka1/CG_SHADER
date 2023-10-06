#pragma once
class Object
{

public:

	Object();
	virtual ~Object();

	virtual void Init()=0;
	virtual void Update()=0;
	virtual void Render()=0;
	

protected:

	Pos m_center{}; // center pos 
	Pos m_size{}; // 사이즈 값 
	VAO m_vao;  
	VBO m_vbo; //정점값
	VBO m_vbo2; // 색상값

	float* m_position;
	float m_color[9];


};

