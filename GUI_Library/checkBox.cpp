#include "checkBox.h"
#include "ActionListener.h"

CheckBox::CheckBox(std::string ment)
	: AbstractButton(ment) {}

void CheckBox::repaint(HDC hdc) {
	Component::repaint(hdc);
	//check ป๓ลย
	std::string temp;
	if (checkFlag_) {
		temp = "[v] " + ment_;
	}
	else {
		temp = "[  ] " + ment_;
	}
	TextOutA(hdc, startX_ + 2, startY_ + 1, temp.c_str(), temp.length());
}

void CheckBox::eventHandler(MEvent e) {
	AbstractButton::eventHandler(e);
	if (e.isLButtonUpEvent()) {
		checkFlag_ = !checkFlag_;
	}
}
