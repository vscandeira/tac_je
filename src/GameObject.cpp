#include "Component.h"

GameObject::GameObject() {
	isDead = false;
}

GameObject::~GameObject() {
	int len = components.size();
	for (int i=len; i>0; i--) {
		components[i-1].release();
		components.erase(components.begin() + i - 1);
	}
	components.clear();
	delete &isDead;
}

void GameObject::Update(float dt){
	int len = components.size();
	for (int i=0; i<len; i++) {
		components[i]->Update(dt);
	}
}
void GameObject::Render(){
	int len = components.size();
	for (int i=0; i<len; i++) {
		components[i]->Render();
	}
}
bool GameObject::IsDead(){
	return isDead;
}
void GameObject::RequestDelete(){
	isDead = true;
}

void GameObject::AddComponent(Component* cpt){
	components.push_back(std::unique_ptr<Component> (cpt));
}

void GameObject::RemoveComponent(Component* cpt){
	int len = components.size();
	for (int i=0; i<len; i++) {
		if(components[i] == cpt){
			components[i].release();
			components.erase(components.begin()+i);
			break;
		}
	}
}


Component* GameObject::GetComponent(std::string type){
	Component* retorno = nullptr;
/*	int len = components.size();
	for (int i = 0; i<len; i++) {
		if (components[i]->Is(type)){
			if (type.compare("Sound")==0) {
				retorno = (Sound*) components[i];
			} else if (type.compare("Face")==0) {
				retorno = (Face*) components[i];
			} else if (type.compare("Sprite")==0) {
				retorno = (Sprite*) components[i];
			}
			break;
		}
	}*/
	return retorno;
}

/*
std::unique_ptr<Component> GameObject::GetComponent(std::string type){
	std::unique_ptr<Component> retorno = nullptr;
	int len = components.size();
	for (int i = 0; i<len; i++) {
		if (components[i]->Is(type)){
			if (type.compare("Sound")==0) {
				retorno.reset(components[i]);
//				return std::unique_ptr<Sound> (components[i]);
			} else if (type.compare("Face")==0) {
//				return std::unique_ptr<Face> (components[i]);
			} else if (type.compare("Sprite")==0) {
//				return std::unique_ptr<Sprite> (components[i]);
			}
			break;
		}
	}
	return retorno;
}
*/
