#pragma once

#include <string>
#include "Windows.h"
#include "AbstractButton.h"

class MPoint;

class CheckBox : public AbstractButton {
protected:
	bool checkFlag_ = false;
public:
	CheckBox(std::string ment);
	virtual void eventHandler(MEvent e) override;
	virtual void repaint(HDC hdc) override;
};
