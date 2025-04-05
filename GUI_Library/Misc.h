#pragma once
#include "Windows.h"

// 화면상의 점을 나타내는 클래스.
class MPoint {
public:
	int x_, y_;
	MPoint(int x, int y);
	MPoint();
};

class ActionEvent;
class AbstractButton;

// 이벤트를 클래스화 한다.
class MEvent {
private:
	UINT msg_;
	WPARAM wParam_;
	LPARAM lParam_;

public:
	MEvent();
	MEvent(UINT msg, WPARAM wParam, LPARAM lParam);
	bool isLButtonDownEvent();
	bool isLButtonUpEvent();
	bool isRButtonDownEvent();
	bool isRButtonUpEvent();
	bool isCtrlKeyDown();
	bool isShiftKeyDown();
	int getX();
	int getY();
	MPoint getPoint();
	ActionEvent makeActionEvent(AbstractButton* b);
};

class ActionEvent : public MEvent {
public:
	ActionEvent();
	ActionEvent(UINT msg, WPARAM wParam, LPARAM lParam, AbstractButton* ab);
	AbstractButton* hostButton_; //리스너를 호출한 버튼주소
	AbstractButton* getHostButton(); //getter

};
