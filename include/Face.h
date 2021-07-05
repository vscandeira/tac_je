#ifndef FACE_H_
#define FACE_H_

#include <string>

#include "Component.h"

class Face : public Component {
private:
	int hitpoints;
public:
	Face(GameObject& associated);
	~Face();
	void Damage(int damage);
	void Update(float dt);
	void Render();
	bool Is(std::string type);
};

#endif /* FACE_H_ */
