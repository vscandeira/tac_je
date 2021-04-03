
#include "GameObject.h"

GameObject::GameObject() {
	isDead = false;
}

GameObject::~GameObject() {
	for (int i=components.size(); i>0; i--) {
		delete components[i-1];
	}
	components.clear();
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
	components[components.size()] = cpt;
}
void GameObject::RemoveComponent(Component* cpt){
	int len = components.size();
	for (int i=0; i<len; i++) {
		if(components[i] == cpt){
			delete components[i];
			for (int j = i+1; j<len; j++) {
				components[j-1] = components[j];
			}
			delete components[len];
			break;
		}
	}
}
Component* GameObject::GetComponent(std::string type){
	Component* retorno = nullptr;
	int len = components.size();
	for (int i = 0; i<len; i++) {
		if (components[i]->Is(type)){
			retorno = components[i];
			break;
		}
	}
	return retorno;
}
