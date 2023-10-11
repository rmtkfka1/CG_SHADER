#pragma once



struct vec2 {
	float x;
	float y;


	vec2 operator+(const vec2& other) {
		vec2 temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}

	vec2 operator-(const vec2& other) {
		vec2 temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;
		return temp;
	}

	vec2 operator*(const float r) {
		vec2 temp;
		temp.x = this->x * r;
		temp.y = this->y * r;
		return temp;
	}


	void operator-=(const vec2& p) {
		this->x -= p.x;
		this->y -= p.y;
	}
	void operator+=(const vec2& p) {
		this->x += p.x;
		this->y += p.y;
	}

	bool operator!=(const vec2& p) {
		return (x != p.x || y != p.y);
	}
	bool operator==(const vec2& p) {
		return (x == p.x && y == p.y);
	}
};

struct vec3 {
	float x;
	float y;
	float z;


	vec3 operator+(const vec3& other) {
		vec3 temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		temp.z = this->z + other.z;
		return temp;
	}

	vec3 operator-(const vec3& other) {
		vec3 temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;
		temp.z = this->z - other.z;
		return temp;
	}

	vec3 operator*(const float r) {
		vec3 temp;
		temp.x = this->x * r;
		temp.y = this->y * r;
		temp.z = this->z * r;
		return temp;
	}


	void operator-=(const vec3& p) {
		this->x -= p.x;
		this->y -= p.y;
		this->z -= p.z;
	}
	void operator+=(const vec3& p) {
		this->x += p.x;
		this->y += p.y;
		this->z += p.z;
	}

	bool operator!=(const vec3& p) {
		return (x != p.x || y != p.y || z != p.z);
	}
	bool operator==(const vec3& p) {
		return (x == p.x && y == p.y && z != p.z);
	}
};



struct Color
{
	float R, G, B;
};

