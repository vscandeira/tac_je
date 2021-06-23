
#include "GameObject.h"
#include "Face.h"
#include "Sound.h"
#include "Sprite.h"

GameObject::GameObject() {
	isDead = false;
}

GameObject::~GameObject() {
	for (int i=components.size(); i>0; i--) {
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
void GameObject::AddComponent(std::unique_ptr<Component> cpt){
	components.emplace_back(cpt);
}
void GameObject::RemoveComponent(std::unique_ptr<Component> cpt){
	int len = components.size();
	for (int i=0; i<len; i++) {
		if(components[i] == cpt){
			components.erase(components.begin()+i);
			for (int j = i+1; j<len; j++) {
				components[j-1] = components[j];
			}
			components.erase(components.begin()+len);
			break;
		}
	}
}

std::unique_ptr<Component> GameObject::GetComponent(std::string type){
	std::unique_ptr<Component> retorno = nullptr;
	int len = components.size();
	for (int i = 0; i<len; i++) {
		if (components[i]->Is(type)){
			if (type.compare("Sound")==0) {
				//retorno = components[i];
				return std::make_unique<Sound>(components[i]);
			} else if (type.compare("Face")==0) {
				return std::make_unique<Face>(components[i]);
			} else if (type.compare("Sprite")==0) {
				//retorno = components[i];
				return std::make_unique<Sprite>(components[i]);
				//return (Sprite) components[i];
			}
			//break;
		}
	}
	return retorno;
}

/*
GameObject::GameObject( GameObject& go){
	this->isDead = go.isDead;
	this->components = go.components;
}

///*
GameObject::GameObject(GameObject&& go) noexcept :
		components(std::move(go.components)),       	// explicit move of a member of class type
		isDead(std::exchange(go.isDead,0))				// explicit move of a member of non-class type
{ }

///*
GameObject::GameObject( GameObject& go) : components(go.components), isDead(go.isDead) {
	//std::cout<<"Errado!\n";
	}
*/
