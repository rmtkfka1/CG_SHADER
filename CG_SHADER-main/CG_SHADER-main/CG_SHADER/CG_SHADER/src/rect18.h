#pragma once
//위치를 미리지정할것인가 ? or (0,0,0) 에서 만들고 이동행렬로 옮길것인가?
//위치를 미리지정해서 만들면 0,0,0 으로 이동변환 행렬 적용 -> 회전 행렬 적용 -> 원래 위치로 이동변환 행렬적용
// 
//(0,0,0) 에서 만들면 회전을 안할떄는 transform 매트릭스만 적용 ,
// 애니메이션 이 시작되면 transform * loate * transform 을 적용해야함 

// 위치를 지정해서 6개를 만들건가? vs  위치를 지정하지않고 모두 똑같이 만든다음 회전행렬과 변환을 적용할것인가? 

class rect18
{

public:
	void Init();
	void Update();
	void Render();


	float degree; //회전할때 사용
	float dx;
	float dy;
	float dz;

private:

	VAO _vao;
	VBO _vbo;
	IBO _ibo;



};

