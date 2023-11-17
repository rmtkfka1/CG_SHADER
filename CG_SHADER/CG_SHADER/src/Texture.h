#pragma once

class Texture
{
public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0); //�ؽ�ó�� ���ε��� ����. GPU�� ���� ���� ������ ����
	void Unbind() const;
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }

	int GetSlot() { return m_slot; }

private:
	unsigned int m_RendererID; //������ ���������� �ؽ�ó ��ü�� ���� ID ����
	std::string m_FilePath;    //�ؽ�ó(�̹���) ���� ���
	unsigned char* m_LocalBuffer; //�ؽ�ó ������
	int m_Width, m_Height, m_BPP; //�ؽ�ó ����, BPP(bits per channel)
	int m_slot;

};