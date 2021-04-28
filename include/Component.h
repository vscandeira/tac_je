/*
 * Component.h
 *
 *  Created on: 2 de abr de 2021
 *      Author: Victor Santos Candeira
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <iostream>
#include <string>

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "GameObject.h"

//class GameObject;		// foward declaration para evitar problemas em tempo de compilação

class Component {
protected:
	GameObject& associated;
public:
	Component(GameObject& associated);
	virtual ~Component();
	virtual void Update(float dt)=0;
	virtual void Render()=0;
	virtual bool Is(std::string type)=0;
};

#endif /* COMPONENT_H_ */
