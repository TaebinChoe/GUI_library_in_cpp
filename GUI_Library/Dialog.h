#pragma once
#include "Container.h"
//container의 일종이지만 실제 저장되는 크기가 화면을 모두 덮어서 외부를 클릭할 수 없음
class Dialog : public Container{
protected:
	MPoint startPos_; //눈에 보이는 크기를 위함
	MPoint endPos_;
	//실제 저장되는 크기
	static const int FS_X = 0, FS_Y = 0, F_WIDTH = 5000, F_HEIGHT = 5000;
public:
	Dialog(MPoint start, MPoint end, std::string ment = "");
	virtual void repaint(HDC hdc)override;
};

