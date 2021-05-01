/*
 * Vec2.h
 *
 *  Created on: 3 de abr de 2021
 *      Author: Victor Santos Candeira
 */

#ifndef VEC2_H_
#define VEC2_H_

#include <cmath>
#include <iostream>

class Vec2 {
public:
	float x;
	float y;
	Vec2(float x, float y);
	~Vec2();
	Vec2 GetRotated( double ang );
	Vec2 operator+(Vec2 v);
};

#endif /* VEC2_H_ */
