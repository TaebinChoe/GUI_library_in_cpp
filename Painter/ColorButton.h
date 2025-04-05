#pragma once
#include "button.h"
class ColorButton : public Button{
private:
	int myColor_;

	HBRUSH redBr_;
	HBRUSH blackBr_;
	HBRUSH blueBr_;
public:
	ColorButton(MPoint start, MPoint end, int color,std::string ment = "");
	virtual void repaint(HDC hdc) override;
};

