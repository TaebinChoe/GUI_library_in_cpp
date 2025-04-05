#include "line.h"
#include "PaintPanel.h"

Line::Line(Container* myContainer, const MPoint& sp, const MPoint& ep, int color) : Figure(myContainer, sp, ep, color) {}

void Line::draw() {
	static_cast<PaintPanel*>(myContainer_)->chagePenColor(myColor_);
	MoveToEx(static_cast<PaintPanel*>(myContainer_)->getHdc(), startPos_.x_, startPos_.y_, nullptr);
	LineTo(static_cast<PaintPanel*>(myContainer_)->getHdc(), endPos_.x_, endPos_.y_);
	static_cast<PaintPanel*>(myContainer_)->chagePenColor(PaintPanel::BLACK);
}

