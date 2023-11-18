#pragma once

#include "Object.h"

class Player :public Object
{

	using Super = Object;

public:
	Player(const string& model_filepath);
	~Player();


	void Init() override;
	void Update() override;
	void Render(Shader& shader, glm::mat4 tesk) override;

	void OnComponentBeginOverlap(Collider* collider, Collider* other) override;
	void OnComponentEndOverlap(Collider* collider, Collider* other) override;

public:
	
	bool _collusion = false;

};