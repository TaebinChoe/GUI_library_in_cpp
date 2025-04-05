#pragma once
#include "component.h"
class StaticText : public Component{
public:
	StaticText(std::string ment = ""); //디폴트크기로 생성하고 자리를 따로 지정 받을때
	StaticText(MPoint start, MPoint end, std::string ment = ""); //크기와 시작위치를 직접 정의해 줄때
	void setMent(std::string);
	std::string getMent() const;
	virtual void repaint(HDC hdc)override;
};

