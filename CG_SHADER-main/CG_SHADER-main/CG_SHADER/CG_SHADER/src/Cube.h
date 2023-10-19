#pragma once
class Cube
{

public:

	Cube();
	~Cube();

	void Init(vec3 center, float size , int mode); // mode ==0 �ָ���  , mode ==1 ���̾�
	void Update();
	void Render();

	

protected:

	vec3 m_center{}; // center pos 
	float m_size{}; // ������ �� 

	int m_mode; // ���̾� /�ָ���

	VAO m_vao;
	VBO m_vbo; 
	IBO m_ibo;




};

