#pragma once
class VBO
{

public:

	VBO(const void* data, unsigned int size); //size�� byte ������, �������� Ÿ���� �𸣱� ������ void*��.
	~VBO();


	void Bind() const;
	void Unbind() const;
	void Delete() const;
	
	const unsigned int GetID() { return m_RendererID; }
private:

	unsigned int m_RendererID{};

};

