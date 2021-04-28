
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
//#include "Component.h"
#include "Rect.h"

class Component;		// foward declaration para evitar problemas em tempo de compilação

class GameObject {
private:
	std::vector<Component*> components;
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
	Component* GetComponent(std::string type);
//	std::unique_ptr<Component> GetComponent(std::string type);
};

#endif /* GAMEOBJECT_H_ */
