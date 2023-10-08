#pragma once

class p13;

class ObjectManger
{

public:
	static ObjectManger* GetInstance()
	{
		static ObjectManger mg;
		return &mg;
	}


public:

	vector<p13*>& GetTri() { return v_p13; } //외부 CPP,헤더파일에서 벡터가져오기//
	vector<Shader*>& GetShader() { return v_shader; } //외부 CPP,헤더파일에서 벡터가져오기//

private:

	vector<p13*> v_p13;
	vector<Shader*> v_shader;


};