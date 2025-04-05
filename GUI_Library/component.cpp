#include "component.h"
#include "frame.h"

Component::Component(std::string ment)
	: ment_(ment) {}

Component::Component(MPoint start, MPoint end, std::string ment) : ment_(ment) {
	if (start.x_ <= end.x_) {
		startX_ = start.x_;
		width_ = end.x_ - start.x_;
	}
	else {
		startX_ = end.x_;
		width_ = start.x_ - end.x_;
	}

	if (start.y_ <= end.y_) {
		startY_ = start.y_;
		height_= end.y_ - start.y_;
	}
	else {
		startY_ = end.y_;
		height_ = start.y_ - end.y_;
	}
}

void Component::setStartX(int x) {
	startX_ = x;
}

void Component::setStartY(int y) {
	startY_ = y;
}

int Component::getEndX() const {
	return startX_ + width_;
}

bool Component::isInclude(const MPoint& point) {
	return (startX_ <= point.x_ && point.x_ <= startX_ + width_ && startY_ <= point.y_ && point.y_ <= startY_ + height_);
}

void Component::repaint(HDC hdc) {
	Rectangle(hdc, startX_, startY_, startX_ + width_, startY_ + height_);
}

void Component::eventHandler(MEvent e) {
	//blank
}

Component::~Component(){
	//blank
}