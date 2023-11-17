#pragma once
#include "Object.h"
class Box :public Object
{

public:
	Box(const string& model_filepath, const string& texture_filepath,int slot);
	~Box();


	void Init() override;
	void Update() override;
	void Render(Shader& shader) override;

private:



};

