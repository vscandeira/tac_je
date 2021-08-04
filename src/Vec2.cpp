#include <cmath>
#include <iostream>

#include "Vec2.h"

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;

}

Vec2::~Vec2() {}

Vec2 Vec2::GetRotated( double ang ){
	double sin_ang, cos_ang;
	sin_ang = sin(ang);
	cos_ang = cos(ang);
	return Vec2( (float) cos_ang*x + sin_ang*y, (float) cos_ang*y - sin_ang*x);
}


Vec2 Vec2::operator+(Vec2 v) {
	return Vec2(this->x + v.x, this->y + v.y);
}
