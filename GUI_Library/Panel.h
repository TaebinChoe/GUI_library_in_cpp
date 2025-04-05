#pragma once
#include "Container.h"
class Panel : public Container{
public:
	Panel(MPoint start, MPoint end, std::string ment = "");
	virtual void repaint(HDC hdc)override;
};

