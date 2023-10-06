#include "pch.h"
#include "Object.h"

Object::Object()
{

}

Object::~Object()
{
	delete[] m_position;
}






