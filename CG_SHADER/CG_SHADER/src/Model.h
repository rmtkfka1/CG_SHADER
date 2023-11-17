#pragma once



class Model
{
public:
	Model();
	~Model();

	void LoadModel(const std::string& fileName);
	void ClearModel();

	void RenderModel(Shader& shader);

private:
	void LoadNode(aiNode* node, const aiScene* scene);
	void LoadMesh(aiMesh* mesh, const aiScene* scene);
	void LoadMaterials(const aiScene* scene);

	std::vector<VAO*> VAOs;
	std::vector<VBO*> VBOs;
	std::vector<IBO*> IBOs;
	std::vector<Texture*> m_TextureList;
	std::vector<unsigned int> m_MeshToTex;
};