/*
 * Rect.cpp
 *
 *  Created on: 2 de abr de 2021
 *      Author: vitim
 */

#include "Rect.h"

Rect::Rect(float x, float y, float w, float h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

Rect::~Rect() {
	delete x, y, w, h;
}

