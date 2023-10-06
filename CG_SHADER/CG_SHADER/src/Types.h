#pragma once



struct Pos {
	float x;
	float y;


	Pos operator+(const Pos& other) {
		Pos temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}

	Pos operator-(const Pos& other) {
		Pos temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;
		return temp;
	}

	Pos operator*(const float r) {
		Pos temp;
		temp.x = this->x * r;
		temp.y = this->y * r;
		return temp;
	}


	void operator-=(const Pos& p) {
		this->x -= p.x;
		this->y -= p.y;
	}
	void operator+=(const Pos& p) {
		this->x += p.x;
		this->y += p.y;
	}

	bool operator!=(const Pos& p) {
		return (x != p.x || y != p.y);
	}
	bool operator==(const Pos& p) {
		return (x == p.x && y == p.y);
	}
};

struct Pos2D
{
	float x1, y1, x2, y2;

};

struct Color
{
	float R, G, B;
};

