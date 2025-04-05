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
	std::string ment_; //����

	static const int default_width = 90;// �⺻ �ʺ�
	static const int default_height = 20; // �⺻ ����

public:
	Component(std::string ment = ""); //����Ʈũ��� �����ϰ� �ڸ��� ���� ���� ������
	Component(MPoint start, MPoint end, std::string ment = ""); //ũ��� ������ġ�� ���� ������ �ٶ�
	virtual ~Component();
	void setStartX(int x);
	void setStartY(int y);
	bool isInclude(const MPoint& point);
	virtual void repaint(HDC hdc);
	int getEndX()const; //���� ��ư ��ġ ������ ����

	virtual void eventHandler(MEvent e);
};
