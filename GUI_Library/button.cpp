#include "button.h"
#include "frame.h"
#include "ActionListener.h"

Button::Button(std::string ment)
	: AbstractButton(ment) {}

Button::Button(MPoint start, MPoint end, std::string ment) : AbstractButton(start, end, ment) {}

void Button::repaint(HDC hdc) {
	Component::repaint(hdc);
	TextOutA(hdc, startX_ + 2, startY_ + 1, ment_.c_str(), ment_.length());
}