#pragma once

#include <string>
#include "Windows.h"
#include "AbstractButton.h"

class MPoint;

class Button : public AbstractButton {
public:
	Button(std::string ment);
	Button(MPoint start, MPoint end, std::string ment = "");
	virtual void repaint(HDC hdc) override;

};