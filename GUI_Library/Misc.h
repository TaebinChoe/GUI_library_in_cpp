#pragma once
#include "Windows.h"

// ȭ����� ���� ��Ÿ���� Ŭ����.
class MPoint {
public:
	int x_, y_;
	MPoint(int x, int y);
	MPoint();
};

class ActionEvent;
class AbstractButton;

// �̺�Ʈ�� Ŭ����ȭ �Ѵ�.
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
	AbstractButton* hostButton_; //�����ʸ� ȣ���� ��ư�ּ�
	AbstractButton* getHostButton(); //getter

};
