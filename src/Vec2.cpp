/*
 * Vec2.cpp
 *
 *  Created on: 3 de abr de 2021
 *      Author: vitim
 */

#include "Vec2.h"

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;

}

Vec2::~Vec2() {
	delete x, y;
}

