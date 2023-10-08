#pragma once
class p133:public Object
{
public:


	p133();
	~p133();

	void Init() override;
	void Update() override;
	void Render() override;

	int checkbox(); 
	Pos diff;

};

