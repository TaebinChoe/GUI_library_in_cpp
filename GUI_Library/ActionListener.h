#pragma once
#include "Misc.h"

class Container;

class ActionListener{
public:
	ActionListener();
	ActionListener(Container* myContainer);
	virtual void actionPerformed(ActionEvent ae) = 0;
	void setContainer(Container* myContainer);
protected:
	Container* myContainer_ = nullptr;
};

