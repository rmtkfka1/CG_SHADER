#pragma once
class Object
{

public:

	Object();
	~Object();

	void Init();
	void Update();
	void Render();


private:

	Pos m_pos[3]{};
	Pos m_center{};
	float m_size{};
	VAO m_vao;
	VBO m_vbo; //������
	VBO m_vbo2;  // ����

	float* m_position;
	float m_color[9];



};

