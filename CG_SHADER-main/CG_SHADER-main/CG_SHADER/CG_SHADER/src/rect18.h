#pragma once
//��ġ�� �̸������Ұ��ΰ� ? or (0,0,0) ���� ����� �̵���ķ� �ű���ΰ�?
//��ġ�� �̸������ؼ� ����� 0,0,0 ���� �̵���ȯ ��� ���� -> ȸ�� ��� ���� -> ���� ��ġ�� �̵���ȯ �������
// 
//(0,0,0) ���� ����� ȸ���� ���ҋ��� transform ��Ʈ������ ���� ,
// �ִϸ��̼� �� ���۵Ǹ� transform * loate * transform �� �����ؾ��� 

// ��ġ�� �����ؼ� 6���� ����ǰ�? vs  ��ġ�� ���������ʰ� ��� �Ȱ��� ������� ȸ����İ� ��ȯ�� �����Ұ��ΰ�? 

class rect18
{

public:
	void Init();
	void Update();
	void Render();


	float degree; //ȸ���Ҷ� ���
	float dx;
	float dy;
	float dz;

private:

	VAO _vao;
	VBO _vbo;
	IBO _ibo;



};

