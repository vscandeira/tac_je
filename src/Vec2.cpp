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

Vec2 Vec2::GetRotated( float ang ){
	return Vec2(this->x, this->y);
}

Vec2 Vec2::operator+(Vec2 v) {
	return Vec2(this->x + v.x, this->y + v.y);
}
