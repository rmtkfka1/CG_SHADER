#pragma once
class Renderer
{
public:

	//ȭ�鿡 ���𰡸� �׸����ؼ��� Vertex Array (Vertex Buffer�� ���⿡ ���ԵǾ� ����), Index Array, Shader Program�� �ʿ���
	void Draw(const VAO& va, const IBO& ib, const Shader& shader) const;
	void Clear() const;
};

