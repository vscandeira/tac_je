#include "Component.h"
#include "Sound.h"
#include "Face.h"
#include "Sprite.h"

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
	std::unique_ptr<Component> cpt_uni = std::unique_ptr<Component> (cpt);
	components.push_back(std::move(cpt_uni));
}

void GameObject::RemoveComponent(Component* cpt){
	int len = components.size();
	for (int i=0; i<len; i++) {
		if(components[i].get() == cpt){
			components[i].release();
			components.erase(components.begin()+i);
			break;
		}
	}
}

//std::unique_ptr<Component> GameObject::GetComponent(std::string type){
Component* GameObject::GetComponent(std::string type){
//	std::unique_ptr<Component> retorno = nullptr;
	Component* retorno = nullptr;
	int len = components.size();
	for (int i = 0; i<len; i++) {
		if (components[i]->Is(type)){
			if (type.compare("Sound")==0) {
//				return std::unique_ptr<Sound> ((Sound*) components[i].get());
				return (Sound*) components[i].get();
			} else if (type.compare("Face")==0) {
//				return std::unique_ptr<Face> ((Face*) components[i].get());
				return (Face*) components[i].get();
			} else if (type.compare("Sprite")==0) {
//				return std::unique_ptr<Sprite> ((Sprite*) components[i].get());
				return (Sprite*) components[i].get();
			}
			break;
		}
	}
	return retorno;
}
