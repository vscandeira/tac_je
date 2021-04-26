#include "Component.h"

Component::Component(GameObject& associated) : associated(associated) {
	this->associated = associated;

}

Component::~Component() {
	delete (&associated);
}
