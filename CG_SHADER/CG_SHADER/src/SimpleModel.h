#pragma once
#include "Object.h"



class SimpleModel :public Object
{

public:
	SimpleModel(const string& model_filepath);
	~SimpleModel();


	void Init() override;
	void Update() override;
	void Render(Shader& shader) override;

private:


};

