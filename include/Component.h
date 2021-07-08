#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>
#include "GameObject.h"

class Component {
protected:
	GameObject& associated;
public:

	Component(GameObject& associated);
	virtual ~Component();
	virtual void Update(float dt)=0;
	virtual void Render()=0;
	virtual bool Is(std::string type)=0;

	Component(Component& go)=delete;
	Component(Component&& go)=default;
};

#endif /* COMPONENT_H_ */
