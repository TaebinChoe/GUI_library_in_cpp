#include "ellipse.h"
#include "PaintPanel.h"

Ellip::Ellip(Container* myContainer, const MPoint& sp, const MPoint& ep, int color) : Figure(myContainer, sp, ep, color) {}

void Ellip::draw() {
	static_cast<PaintPanel*>(myContainer_)->chagePenColor(myColor_);
	Ellipse(static_cast<PaintPanel*>(myContainer_)->getHdc(), startPos_.x_, startPos_.y_, endPos_.x_, endPos_.y_);
	static_cast<PaintPanel*>(myContainer_)->chagePenColor(PaintPanel::BLACK);
}


