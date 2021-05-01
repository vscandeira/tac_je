
#include "GameObject.h"
#include "Face.h"
#include "Sound.h"
#include "Sprite.h"

GameObject::GameObject() {
	isDead = false;
}

GameObject::~GameObject() {
	for (int i=components.size(); i>0; i--) {
		delete components[i-1];
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
	components.emplace_back(cpt);
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
//std::unique_ptr<Component> GameObject::GetComponent(std::string type){
	Component* retorno = nullptr;
	int len = components.size();
	for (int i = 0; i<len; i++) {
		if (components[i]->Is(type)){
			if (type.compare("Face")==0) {
				retorno = components[i];
				//return (Face) components[i];
				//retorno = std::make_unique<Face>(components[i]);
			} else if (type.compare("Sound")==0) {
				retorno = components[i];
				//retorno = std::make_unique<Sound>(components[i]);
				//return (Sound) components[i];
			} else if (type.compare("Sprite")==0) {
				retorno = components[i];
				//retorno = std::make_unique<Sprite>(components[i]);
				//return (Sprite) components[i];
			}
			break;
		}
	}
	return retorno;
}
