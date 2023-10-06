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
	Pos m_size{}; // ������ �� 
	VAO m_vao;  
	VBO m_vbo; //������
	VBO m_vbo2; // ����

	float* m_position;
	float m_color[9];


};

