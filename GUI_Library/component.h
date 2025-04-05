#pragma once

#include <string>
//#include "myList.h"
#include "Windows.h"
#include "Misc.h"

class MPoint;
class Frame;
class ActionListener;

class Component {
protected:
	
	int startX_ = 0;
	int startY_ = 0;
	int width_ = default_width;
	int height_ = default_height;
	std::string ment_; //문구

	static const int default_width = 90;// 기본 너비
	static const int default_height = 20; // 기본 높이

public:
	Component(std::string ment = ""); //디폴트크기로 생성하고 자리를 따로 지정 받을때
	Component(MPoint start, MPoint end, std::string ment = ""); //크기와 시작위치를 직접 정의해 줄때
	virtual ~Component();
	void setStartX(int x);
	void setStartY(int y);
	bool isInclude(const MPoint& point);
	virtual void repaint(HDC hdc);
	int getEndX()const; //다음 버튼 위치 선정을 위함

	virtual void eventHandler(MEvent e);
};
