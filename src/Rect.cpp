/*
 * Rect.cpp
 *
 *  Created on: 2 de abr de 2021
 *      Author: Victor Santos Candeira
 */

#include "Rect.h"

Rect::Rect() {
	x = 0;
	y = 0;
	w = 0;
	h = 0;
}

Rect::Rect(float x, float y, float w, float h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

Rect::~Rect() {
	delete &x;
	delete &y;
	delete &w;
	delete &h;
}

bool Rect::Contains( std::array<float, 2> arr ){
	bool retorno = false;
	if (this->x == arr[0]) {
		if (this->y == arr[1]) {
			retorno = true;
		}
	}
	return retorno;
}
