#include "Dialog.h"

Dialog::Dialog(MPoint start, MPoint end, std::string ment) 
	: Container(MPoint(FS_X,FS_Y), MPoint(FS_X +F_WIDTH, FS_Y + F_HEIGHT), ment){
	startPos_ = start;
	endPos_ = end;
}

void Dialog::repaint(HDC hdc) {
	Rectangle(hdc, startPos_.x_, startPos_.y_ , endPos_.x_, endPos_.y_);//보이는 크기로 테두리를 그림
	Container::repaint(hdc);
}
