#pragma once
#include "Container.h"
//container�� ���������� ���� ����Ǵ� ũ�Ⱑ ȭ���� ��� ��� �ܺθ� Ŭ���� �� ����
class Dialog : public Container{
protected:
	MPoint startPos_; //���� ���̴� ũ�⸦ ����
	MPoint endPos_;
	//���� ����Ǵ� ũ��
	static const int FS_X = 0, FS_Y = 0, F_WIDTH = 5000, F_HEIGHT = 5000;
public:
	Dialog(MPoint start, MPoint end, std::string ment = "");
	virtual void repaint(HDC hdc)override;
};

