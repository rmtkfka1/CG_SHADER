#pragma once


class p13 : public Object
{

public:

	p13();
	~p13();

	void Init() override;
	void Update() override;
	void Render() override;

	Pos diff;
private:

	int checkbox();
};

