#include "Face.h"
#include "Sound.h"
#include "GameObject.h"

Face::Face(GameObject& associated): Component(associated) {
	hitpoints = 30;

}

Face::~Face() {}

void Face::Damage(int damage){
	hitpoints -= damage;
	if (hitpoints <= 0) {
		std::string s = "Sound";
		if (associated.GetComponent(s) != nullptr) {
			Sound* sound = (Sound*)associated.GetComponent(s);
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
