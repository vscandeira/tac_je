/*
 * Vec2.cpp
 *
 *  Created on: 3 de abr de 2021
 *      Author: Victor Santos Candeira
 */

#include "Vec2.h"

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;

}

Vec2::~Vec2() {
	delete &x;
	delete &y;
}

Vec2 Vec2::GetRotated( double ang ){
	double sin_ang, cos_ang;
	sin_ang = sin(ang);
	cos_ang = cos(ang);
	Vec2 vec = Vec2( (float) cos_ang*x + sin_ang*y, (float) cos_ang*y - sin_ang*x);
	std::cout << "Teste Vec2 3 - vec1x: " << this->x << " - vec1y: " << this->y << " - vec2x: " << vec.x << " - vec2y: " << vec.y << std::endl;
	return vec;
}

Vec2 Vec2::operator+(Vec2 v) {
	return Vec2(this->x + v.x, this->y + v.y);
}
