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



	vector<p14_world*>& Get_P14_world() { return v_p14_world; } //�ܺ� CPP,������Ͽ��� ���Ͱ�������//
	vector<Shader*>& Get_Shader() { return v_shader; } //�ܺ� CPP,������Ͽ��� ���Ͱ�������//


private:

	vector<p14_world*> v_p14_world;
	vector<Shader*> v_shader;



};

