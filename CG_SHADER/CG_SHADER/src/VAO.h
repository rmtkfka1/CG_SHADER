#pragma once


class VAO
{

public:
	VAO();
	~VAO();


	void Gen();
	void Bind() const;
	void Unbind() const;
	void Delete() const;

	const unsigned int GetID() { return m_RendererID; }


private:
	unsigned int m_RendererID{};


};