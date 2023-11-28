#pragma once

class p14_world;
class Shader;
class ObjectManager
{

public:
	static ObjectManager* GetInstance()
	{
		static ObjectManager OM;
		return &OM;
	}

	void AddShader(Shader *shader);


	vector<Shader*>& Get_Shader() { return v_shader; } //�ܺ� CPP,������Ͽ��� ���Ͱ�������//



private:
	vector<Shader*> v_shader;
};

