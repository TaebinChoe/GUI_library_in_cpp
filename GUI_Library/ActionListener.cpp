#include "ActionListener.h"

ActionListener::ActionListener() {}

ActionListener::ActionListener(Container* myContainer) {
	myContainer_ = myContainer;
}

void ActionListener::setContainer(Container* myContainer) {
	myContainer_ = myContainer;
}
