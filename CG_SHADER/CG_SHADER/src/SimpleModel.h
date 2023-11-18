#pragma once
#include "Object.h"



class SimpleModel :public Object
{

	using Super = Object;

public:
	SimpleModel(const string& model_filepath);
	~SimpleModel();


	void Init() override;
	void Update() override;
	void Render(Shader& shader, glm::mat4 tesk) override;

private:


};

