/*
 * Face.h
 *
 *  Created on: 3 de abr de 2021
 *      Author: Victor Santos Candeira
 */

#ifndef FACE_H_
#define FACE_H_

#include <iostream>
#include <string>
#include <memory>

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Component.h"
#include "Sound.h"

class GameObject;

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
