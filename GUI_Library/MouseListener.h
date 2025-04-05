#pragma once
#include "Misc.h"

class Container;

class MouseListener{
public:
	MouseListener();
	MouseListener(Container* myContainer);
	virtual void mousePressed(MEvent e ) = 0;
	virtual void mouseReleased(MEvent e) = 0;
	void setContainer(Container* myContainer);
protected:
	Container* myContainer_ = nullptr;
};