#pragma once
class Object
{

public:

	Object();
	~Object();

	void Init();
	void Update();
	void Render();

	bool click[4];

	

private:

	Pos m_pos[3]{};
	Pos m_center{};
	Pos m_size{};
	VAO m_vao;
	VBO m_vbo; //������
	VBO m_vbo2; // ����


	int checkbox();
	float* m_position;
	float m_color[9];



};

