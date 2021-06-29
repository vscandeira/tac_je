
#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Rect.h"
#include "Component.h"

//class Component;

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
	void AddComponent(std::unique_ptr<Component> cpt);
	void RemoveComponent(std::unique_ptr<Component> cpt);
//	std::unique_ptr<Component> GetComponent(std::string type);
	Component* GetComponent(std::string type);
};

#endif /* GAMEOBJECT_H_ */
