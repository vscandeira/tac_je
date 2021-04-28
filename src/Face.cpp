/*
 * Face.cpp
 *
 *  Created on: 3 de abr de 2021
 *      Author: Victor Santos Candeira
 */

#include "Face.h"

Face::Face(GameObject& associated): Component(associated) {
	//construir mãe
	hitpoints = 30;

}

Face::~Face() {
	delete &hitpoints;
}

void Face::Damage(int damage){
	hitpoints -= damage;
	if (hitpoints <= 0) {
		std::string f = "Sound";
		if (associated.GetComponent(f) != nullptr) {
			Sound* sound = (Sound*)associated.GetComponent(f);
			sound->Play();
		}
		associated.RequestDelete();
	}
}
void Face::Update(float dt){
	return;
}
void Face::Render(){
	return;
}
bool Face::Is(std::string type){
	bool flag = false;
	if (type.compare("Face")==0) {
		flag = true;
	}
	return flag;
}
