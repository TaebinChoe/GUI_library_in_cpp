#pragma once
#include "component.h"
class StaticText : public Component{
public:
	StaticText(std::string ment = ""); //����Ʈũ��� �����ϰ� �ڸ��� ���� ���� ������
	StaticText(MPoint start, MPoint end, std::string ment = ""); //ũ��� ������ġ�� ���� ������ �ٶ�
	void setMent(std::string);
	std::string getMent() const;
	virtual void repaint(HDC hdc)override;
};

