#include "Component.h"

GameObject& Component::associated = nullptr;

Component::Component(GameObject& associated) {
	this->associated = associated;

}

Component::~Component() {
	delete associated;
}
