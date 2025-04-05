#include "ColorButton.h"
#include "PaintPanel.h"

ColorButton::ColorButton(MPoint start, MPoint end,int color ,std::string ment) 
	: Button(start, end, ment), myColor_(color) {
	//Brushµé »ý¼º
	redBr_ = CreateSolidBrush(RGB(255, 0, 0));
	blueBr_ = CreateSolidBrush(RGB(0, 0, 255));
	blackBr_ = CreateSolidBrush(RGB(0, 0, 0));
}

void ColorButton::repaint(HDC hdc) {
	HBRUSH oldBr;
	switch (myColor_) {
	case PaintPanel::RED:
		oldBr =(HBRUSH) SelectObject(hdc, redBr_);
		break;
	case PaintPanel::BLUE:
		oldBr = (HBRUSH)SelectObject(hdc, blueBr_);
		break;
	//case PaintPanel::BLACK:	
	default:
		oldBr = (HBRUSH)SelectObject(hdc, blackBr_);
	}

	Component::repaint(hdc);
	SelectObject(hdc, oldBr);
}