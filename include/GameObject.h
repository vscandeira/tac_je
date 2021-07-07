
#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <string>
#include <vector>
#include <memory>
#include "Rect.h"
#include "GameObject.h"

class Component;

class GameObject {
private:
	std::vector<std::unique_ptr<Component>> components;
	bool isDead;
public:
	Rect box;

	GameObject();
	~GameObject();
	void Update(float dt);
	void Render();
	bool IsDead();
	void RequestDelete();
	void AddComponent(Component* cpt);
	void RemoveComponent(Component* cpt);
//	std::unique_ptr<Component> GetComponent(std::string type);
	Component* GetComponent(std::string type);
};

#endif /* GAMEOBJECT_H_ */
