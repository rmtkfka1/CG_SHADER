#pragma once
class IBO
{

public:
	IBO();
	IBO(const unsigned int* data, unsigned int count); //index�� (��κ�) unsigned int* Ÿ��. count�� ����(size�� �ٸ�)
	
	~IBO();


	void Gen(const unsigned int* data, unsigned int count) ;
	void Bind() const;
	void Unbind() const;
	void Delete() const;


	const int GetID() { return m_RendererID; }
	inline unsigned int GetCount() const { return m_Count; }

private:
	unsigned int m_RendererID;
	unsigned int m_Count;
};
