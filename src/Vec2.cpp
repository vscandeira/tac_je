#include <cmath>
#include <iostream>

#include "Vec2.h"

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
	std::cout<<"\nVec2 Constructor: X " << this->x << " - Y " << this->y << std::endl;

}

Vec2::~Vec2() {
	delete &x;
	delete &y;
	std::cout<<"\nVec2 Destructor\n";
}

Vec2 Vec2::GetRotated( double ang ){
	double sin_ang, cos_ang;
	sin_ang = sin(ang);
	cos_ang = cos(ang);
	std::cout<<"\nVec2 GetRotated: Angle "<<ang<<" - sin_ang "<<sin_ang<<" - cos_ang "<<cos_ang<<std::endl;
	return Vec2( (float) cos_ang*x + sin_ang*y, (float) cos_ang*y - sin_ang*x);
}

Vec2 Vec2::operator+(Vec2 v) {
	std::cout<<"\nVec2 operator+"<< std::endl;
	return Vec2(this->x + v.x, this->y + v.y);
}
