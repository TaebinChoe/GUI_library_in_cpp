#include "Container.h"
#include "MouseListener.h"
#include "Misc.h"

Container::Container(std::string ment) : Component(ment) {}

Container::Container(MPoint start, MPoint end, std::string ment) : Component(start,end,ment){}

Container::~Container() {
	for (MyList<Component*>::iterator i = myComponents_.begin(); i != myComponents_.end(); ++i) {
		delete(*i);
	}
}


void Container::addComponent(Component* comp) {
	myComponents_.push_back(comp);
}


Component* Container::popComponent() {
	MyList<Component*>::reverse_iterator ri = myComponents_.rbegin();
	if (ri != myComponents_.rend()) {
		myComponents_.remove(ri);
		return (*ri);
	}
	else {
		return nullptr;
	}
}

Component* Container::findComponent(MPoint pos) {
	/*
	MyList<Component*>::iterator i = myComponents_.begin();
	for (; i != myComponents_.end(); ++i) {
		if ((*i)->isInclude(pos)) {
			return *i;
		}
	}
	*/

	MyList<Component*>::reverse_iterator ri = myComponents_.rbegin();
	for (; ri != myComponents_.rend(); ++ri) {
		if ((*ri)->isInclude(pos)) {
			return *ri;
		}
	}
	return nullptr;
}

void Container::repaint(HDC hdc) {
	for (MyList<Component*>::iterator i = myComponents_.begin(); i != myComponents_.end(); ++i) {
		(*i)->repaint(hdc);
	}
}


void Container::eventHandler(MEvent e) {
	if (Component* temp = findComponent(e.getPoint())) {
		temp->eventHandler(e);
	}

	//버튼이 안눌렸을때
	if (isInclude(e.getPoint())) {
		Component* temp;
		if (e.isLButtonDownEvent()) {
			//MouseListener의 함수
			for (MyList<MouseListener*>::iterator i = myMouseListeners_.begin(); i != myMouseListeners_.end(); ++i) {
				(*i)->mousePressed(e);
			}
		}
		else if (e.isLButtonUpEvent()) {
			for (MyList<MouseListener*>::iterator i = myMouseListeners_.begin(); i != myMouseListeners_.end(); ++i) {
				(*i)->mouseReleased(e);
			}
		}
	}
}

void Container::addMouseListener(MouseListener* ml) {
	myMouseListeners_.push_back(ml);
}

