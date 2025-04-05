#include "Misc.h"

MEvent::MEvent() {}

MEvent::MEvent(UINT msg, WPARAM wParam, LPARAM lParam) :
	msg_(msg), wParam_(wParam), lParam_(lParam)
{
	//  Nothing to do here.
}
//is ~ Event幅 绰 msg甫 贸府


bool MEvent::isLButtonDownEvent() {
	return (msg_ == WM_LBUTTONDOWN);
}

bool MEvent::isLButtonUpEvent() {
	return (msg_ == WM_LBUTTONUP);
}

bool MEvent::isRButtonDownEvent() {
	return (msg_ == WM_RBUTTONDOWN);
}

bool MEvent::isRButtonUpEvent() {
	return (msg_ == WM_RBUTTONUP);
}

bool MEvent::isCtrlKeyDown() {
	return (wParam_ & MK_CONTROL) ? true : false;
}

bool MEvent::isShiftKeyDown() {
	return (wParam_ & MK_SHIFT) ? true : false;
}
int MEvent::getX() {
	return LOWORD(lParam_);
}

int MEvent::getY() {
	return HIWORD(lParam_);
}

MPoint MEvent::getPoint() {
	return MPoint(LOWORD(lParam_), HIWORD(lParam_));
}

//MPoint积己磊
MPoint::MPoint(int x, int y) : x_(x), y_(y) {

}

MPoint::MPoint() : x_(0), y_(0) {

}

ActionEvent MEvent::makeActionEvent(AbstractButton* ab) {
	return ActionEvent(msg_, wParam_, lParam_, ab);
}

ActionEvent::ActionEvent() : MEvent() {}

ActionEvent::ActionEvent(UINT msg, WPARAM wParam, LPARAM lParam, AbstractButton* ab)
	: MEvent(msg,wParam,lParam), hostButton_(ab){}

AbstractButton* ActionEvent::getHostButton() {
	return hostButton_;
}