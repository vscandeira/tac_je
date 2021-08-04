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

Rect::~Rect() {}

bool Rect::Contains( std::array<float, 2> arr ){
	bool retorno = false;
	if ( (arr[0] >= (this->x-this->w/2) ) && (arr[0] <= (this->x+this->w/2) ) ) {
		if ( (arr[1] >= (this->y-this->h/2) ) && (arr[1] <= (this->y+this->h/2) ) ) {
			retorno = true;
		}
	}
	return retorno;
}
