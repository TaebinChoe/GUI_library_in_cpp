#pragma once
#include "Container.h"
class ToolBar : public Container{
public:
	ToolBar(MPoint start, MPoint end, std::string ment = "");
	virtual void addComponent(Component* comp) override;
	virtual void repaint(HDC hdc)override;
};

