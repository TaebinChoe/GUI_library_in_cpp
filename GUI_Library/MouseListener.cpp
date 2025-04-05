#include "MouseListener.h"

MouseListener::MouseListener() {}

MouseListener::MouseListener(Container* myContainer) {
	myContainer_ = myContainer;
}

void MouseListener::setContainer(Container* myContainer) {
	myContainer_ = myContainer;
}
