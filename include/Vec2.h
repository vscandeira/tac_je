#ifndef VEC2_H_
#define VEC2_H_

class Vec2 {
public:
	float x;
	float y;
	Vec2(float x, float y);
	~Vec2();
	Vec2 GetRotated( double ang );
	Vec2 operator+(Vec2 v);
//	Vec2& operator+(const Vec2& v);
};

#endif /* VEC2_H_ */
