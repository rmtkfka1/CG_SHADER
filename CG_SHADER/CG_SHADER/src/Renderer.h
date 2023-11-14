#pragma once
class Renderer
{
public:

	//화면에 무언가를 그리위해서는 Vertex Array (Vertex Buffer는 여기에 포함되어 있음), Index Array, Shader Program이 필요함
	void Draw(const VAO& va, const IBO& ib, const Shader& shader) const;
	void Clear() const;
};

