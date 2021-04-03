/*
 * Face.cpp
 *
 *  Created on: 3 de abr de 2021
 *      Author: vitim
 */

#include "Face.h"

Face::Face(GameObject& associated) {
	//construir mãe
	hitpoints = 30;

}

Face::~Face() {
	delete hitpoints;
}

void Damage(int damage){
	hitpoints -= damage;
	if (hitpoints <= 0) {
		associated.GetComponente()->Play();
		associated.RequestDelete();
	}
}
void Update(float dt){
	return;
}
void Render(){
	return;
}
bool Is(std::string type){
	bool flag = false;
	if (type.compare("Face")==0) {
		flag = true;
	}
	return flag;
}
