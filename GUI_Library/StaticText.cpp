#include "StaticText.h"

StaticText::StaticText(std::string ment) : Component(ment) {}

StaticText::StaticText(MPoint start, MPoint end, std::string ment) : Component(start, end, ment) {}

void StaticText::setMent(std::string ment) {
	ment_ = ment;
}

std::string StaticText::getMent() const {
	return ment_;
}

void StaticText::repaint(HDC hdc) {
	Component::repaint(hdc);
	TextOutA(hdc, startX_ + 50, startY_ + 30, ment_.c_str(), ment_.length());
}